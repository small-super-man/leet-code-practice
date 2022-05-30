//
// Created by tangchao on 2022/5/19.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode *one, const ListNode *two) {
            return one->val > two->val;
        };
        priority_queue<ListNode *, vector<ListNode*>, decltype(cmp)> prior_queue(cmp);

        for (auto iter = lists.begin(); iter != lists.end(); ++iter) {
            if (*iter) {
                prior_queue.push(*iter);
            }
        }

        ListNode *head = new ListNode();
        ListNode *p = head;
        while (!prior_queue.empty()) {
            p->next = prior_queue.top();
            prior_queue.pop();
            p = p->next;
            if (p->next) {
               prior_queue.push(p->next);
            }
            p->next = nullptr;
        }

        ListNode *result = head->next;
        delete head;
        return result;
    }
};