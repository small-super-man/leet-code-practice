//
// Created by tangchao on 2022/5/29.
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
    ListNode* _sortList(ListNode* head, int num) {
        if (num <= 1) {
            return  head;
        }

        int left_num = num / 2;
        int right_num = left_num + (num & 1);

        int i = 0;
        ListNode *pre = nullptr;
        ListNode *p = head;
        while (i < left_num) {
            pre = p;
            p = p->next;
            ++i;
        }
        pre->next = nullptr;

        ListNode *left_list_head = _sortList(head, left_num);
        ListNode *right_list_head = _sortList(p, right_num);

        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;
        while (left_list_head && right_list_head) {
            ListNode *p = nullptr;
            if (left_list_head->val < right_list_head->val) {
                p = left_list_head;
                left_list_head = left_list_head->next;
            } else {
                p = right_list_head;
                right_list_head = right_list_head->next;
            }

            if (nullptr == new_tail) {
                new_head = new_tail = p;
            } else {
                new_tail->next = p;
                new_tail = new_tail->next;
            }

            new_tail->next = nullptr;
        }

        if (left_list_head) {
           new_tail->next = left_list_head;
        } else {
           new_tail->next = right_list_head;
        }

        return new_head;
    }

    ListNode* sortList(ListNode* head) {
       int num = 0;
       ListNode *p = head;
       while (p) {
           ++num;
           p = p->next;
       }

       return _sortList(head,  num);
    }
};