//
// Created by tangchao on 2022/5/15.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        ListNode* p  = l1;
        ListNode* q  = l2;
        int r = 0;
        while (p  && q) {
            int add = r  + p->val  + q->val;
            if (tail) {
                tail->next = new  ListNode(add % 10);
                tail = tail->next;
            }  else {
                head =  tail =  new  ListNode(add % 10);
            }
            r = add / 10;

            p = p->next;
            q = q->next;
        }

        ListNode *points[2] = {p, q};
        for (int i = 0; i < 2; ++i) {
            while (points[i]) {
                int  add = r + points[i]->val;
                tail->next = new ListNode(add % 10);
                tail = tail->next;
                r = add / 10;
                points[i] = points[i]->next;
            }
        }

        if (r) {
            tail->next = new ListNode(r);
        }

        return head;
    }
};