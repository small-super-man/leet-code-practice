//
// Created by tangchao on 2022/5/28.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node  *> node_map;
        Node *p = head;
        Node *new_head = nullptr;
        Node *new_tail = nullptr;
        while (p) {
           if (nullptr == new_tail) {
                new_head = new_tail = new Node(p->val);
                node_map.insert({p, new_tail});
           } else {
                auto iter = node_map.find(p);
                if (iter != node_map.end()) {
                    new_tail->next = iter->second;
                } else {
                    new_tail->next = new Node(p->val);
                    node_map.insert({p, new_tail->next});
                }
                new_tail = new_tail->next;
           }

           auto iter = node_map.find(p->random);
           if (iter != node_map.end()) {
                new_tail->random = iter->second;
           } else {
                if (p->random) {
                    new_tail->random = new Node(p->random->val);
                    node_map.insert({p->random, new_tail->random});
                }
           }
           p = p->next;
        }

        return new_head;
    }
};