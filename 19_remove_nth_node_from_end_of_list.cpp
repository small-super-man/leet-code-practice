//
// Created by tangchao on 2022/5/18.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total_num = 0;
        ListNode *p = head;
        while (p) {
            ++total_num;
            p = p->next;
        }

        int idx = total_num - n;
        if (idx == 0) {
            p = head->next;
            delete head;
            return p;
        }

        ListNode *pre = nullptr;
        p = head;
        while (idx > 0) {
            pre = p;
            p = p->next;
            --idx;
        }

        pre->next = p->next;
        delete p;

        return head;
    }
};

