//
// Created by tangchao on 2022/5/25.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (nullptr == root) {
            return result;
        }

        queue<TreeNode *> traversal_queue;
        traversal_queue.push(root);
        int queue_size = 1;
        while (!traversal_queue.empty()) {
           vector<int> tmp_vec;
           int tmp_size = 0;
           int i = 0;
           while (i < queue_size) {
               TreeNode *front = traversal_queue.front();
               traversal_queue.pop();
               tmp_vec.push_back(front->val);
               if (front->left) {
                   traversal_queue.push(front->left);
                   ++tmp_size;
               }
               if (front->right) {
                   traversal_queue.push(front->right);
                   ++tmp_size;
               }
               ++i;
           }
           queue_size = tmp_size;
           result.push_back(tmp_vec);
        }

        return result;
    }
};