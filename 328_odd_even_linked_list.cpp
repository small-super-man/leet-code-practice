//
// Created by tangchao on 2022/6/7.
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *p = head;
        ListNode *tail = nullptr;
        ListNode *head2 = nullptr;
        ListNode *tail2 = nullptr;

        int list_idx = 1;
        while (p) {
            if (list_idx & 1) {
                if (nullptr == tail) {
                    tail = p;
                } else {
                    tail->next = p;
                    tail = tail->next;
                }
            } else {
                if (nullptr == tail2) {
                    head2 = tail2 = p;
                } else {
                    tail2->next = p;
                    tail2 = tail2->next;
                }
            }

            p = p->next;
            ++list_idx;
        }

        if (tail2) {
            tail2->next = nullptr;
        }

        if (tail) {
            tail->next = head2;
        }

        return head;
    }
};

