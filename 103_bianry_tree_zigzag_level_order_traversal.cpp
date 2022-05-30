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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (nullptr == root) {
           return result;
        }

        queue<TreeNode *> traversal_queue;
        traversal_queue.push(root);
        int current_queue_size = 1;
        int is_left_to_right = true;
        while (!traversal_queue.empty()) {
            vector<int> tmp_vec;
            int next_level_size = 0;
            for (int i = 0; i < current_queue_size; ++i) {
                TreeNode *front = traversal_queue.front();
                traversal_queue.pop();
                tmp_vec.push_back(front->val);
                if (front->left) {
                    traversal_queue.push(front->left);
                    ++next_level_size;
                }
                if (front->right) {
                    traversal_queue.push(front->right);
                    ++next_level_size;
                }
            }

            if (!is_left_to_right) {
                reverse(tmp_vec.begin(), tmp_vec.end());
            }
            result.push_back(tmp_vec);

            is_left_to_right = (!is_left_to_right);
            current_queue_size = next_level_size;
        }

        return result;
    }
};