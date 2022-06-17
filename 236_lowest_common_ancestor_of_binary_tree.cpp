//
// Created by tangchao on 2022/6/3.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }

        vector<TreeNode *> parents_of_p;
        vector<TreeNode *> parents_of_q;

        _findParents(root, p, parents_of_p);
        _findParents(root, q, parents_of_q);

        int i = 0;
        while (i + 1 < parents_of_p.size() && i + 1 < parents_of_q.size() && parents_of_q[i + 1] == parents_of_p[i + 1]) {
            ++i;
        }

        return parents_of_p[i];
    }

private:
    void _findParents(TreeNode *root, TreeNode *r, vector<TreeNode *> &parents) {
        parents.clear();
        TreeNode *p = root;
        while (p || !parents.empty()) {
            while (p) {
                parents.push_back(p);
                p = p->left;
            }

            while (!parents.empty() && p == parents.back()->right) {
                p = parents.back();
                if (p == r) {
                   return;
                }
                parents.pop_back();
            }

            if (!parents.empty()) {
                p = parents.back()->right;
            } else {
                p = nullptr;
            }
        }
    }
};