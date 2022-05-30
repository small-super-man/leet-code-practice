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
    // 包含某个节点的path分成两种:
    // (1)以这个节点为 "root" 的path
    // (2) 这个节点的父节点或者说祖先节点未root的path
    // 最大的path实际上可以通过遍历所有节点为root节点的最大path
    // 计算某个node的最大path时：
    // 左右孩子最大path已算出 : max_path = val(node) + (max_path(left) >0 ? max_path(left) : 0) + (max_path(right) >0 ? max_path(right) : 0)
    // 采用后续遍历
    int maxPathSum(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int max_path = INT_MIN;

        unordered_map<TreeNode *, int> single_path_map;
        vector<TreeNode *> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push_back(p);
                p = p->left;
            }

            while (!st.empty() && p == st.back()->right) {
                p = st.back();
                int tmp_val = p->val;
                int single_val = p->val;
                if (p->left && single_path_map[p->left] > 0) {
                    tmp_val += single_path_map[p->left];
                    single_val += single_path_map[p->left];
                }

                if (p->right && single_path_map[p->right] > 0) {
                    tmp_val += single_path_map[p->right];
                    if (p->val + single_path_map[p->right] > single_val) {
                        single_val = p->val + single_path_map[p->right];
                    }
                }

                if (tmp_val > max_path) {
                   max_path = tmp_val;
                }
                single_path_map[p] = single_val;

                st.pop_back();
            }

            p = nullptr;
            if (!st.empty()) {
               p = st.back()->right;
            }
        }

        return max_path;
    }
};

