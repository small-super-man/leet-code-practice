//
// Created by tangchao on 2022/5/25.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (nullptr == root) {
           return nullptr;
        }

        queue<Node *> traversal_queue;
        traversal_queue.push(root);
        int current_size = 1;
        while (!traversal_queue.empty()) {
            Node *last = nullptr;
            for (int i = 0; i < current_size; ++i) {
               Node *front = traversal_queue.front();
               traversal_queue.pop();
               if (front->left) {
                   traversal_queue.push(front->left);
               }
               if (front->right) {
                   traversal_queue.push(front->right);
               }

               if (nullptr == last) {
                  last = front;
               } else {
                   last->next = front;
                   last = front;
               }
            }
            last->next = nullptr;

            current_size = current_size << 1;
        }

        return root;
    }
};

