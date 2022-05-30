//
// Created by tangchao on 2022/5/24.
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
    // inorder scan
    bool isValidBST(TreeNode* root) {
        vector<TreeNode *> st;
        TreeNode *p = root;
        int pre_val = INT_MIN;
        bool first_flag = true;
        while (p || !st.empty()) {
            while (p) {
               st.push_back(p);
               p = p->left;
            }

            if (first_flag) {
                first_flag = false;
            } else {
                if (st.back()->val <= pre_val) {
                    return false;
                }
            }

            pre_val = st.back()->val;
            p = st.back()->right;
            st.pop_back();
        }

        return true;
    }
};