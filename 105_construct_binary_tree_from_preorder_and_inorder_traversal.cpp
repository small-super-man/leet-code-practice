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
    // use recursion
    TreeNode* _buildTree(const vector<int> &preorder, const vector<int> &inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start >= pre_end) {
           return nullptr;
        }

        int root_val = preorder[pre_start];
        TreeNode *new_root = new TreeNode(root_val);

        int j = in_start;
        while (j < in_end && inorder[j] != root_val) {
           ++j;
        }

        new_root->left = _buildTree(preorder, inorder, pre_start + 1, pre_start + 1 + j - in_start, in_start, j);
        new_root->right = _buildTree(preorder, inorder, pre_start + 1 + j - in_start, pre_end, j + 1, in_end);

        return new_root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        assert(preorder.size() == inorder.size());
        return _buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};