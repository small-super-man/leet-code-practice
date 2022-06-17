//
// Created by tangchao on 2022/6/3.
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
    int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode *> st;
       int count = 0;
       TreeNode *p = root;
       while (p || !st.empty()) {
            while (p) {
               st.push(p);
               p = p->left;
            }

            ++count;
            if (k == count) {
               return st.top()->val;
            }
            auto top = st.top();
            st.pop();
            if (top->right) {
                p = top->right;
            }
       }

       return -1;
    }
};