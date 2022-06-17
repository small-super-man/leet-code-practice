//
// Created by tangchao on 2022/6/6.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode *> my_queue;
        my_queue.push(root);
        while (!my_queue.empty()) {
            auto front = my_queue.front();
            my_queue.pop();
            if (front) {
                result += to_string(front->val);
            }
            if (front) {
                my_queue.push(front->left);
                my_queue.push(front->right);
            }

            if (!my_queue.empty()) {
                result.push_back('#');
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
           return nullptr;
        }

        int start_pos = 0;
        int data_size = data.size();
        vector<string> tokens;
        while (start_pos < data_size) {
           auto pos = data.find('#', start_pos);
           pos = pos == npos ? data_size : pos;
           tokens.push_back(data.substr(start_pos, pos - start_pos));
           start_pos = pos + 1;
        }
        tokens.push_back(std::string(""));

        queue<TreeNode *> pre_level;
        TreeNode *root = new TreeNode(stoi(tokens[0]));
        pre_level.push(root);
        int pos = 1;
        while (!pre_level.empty()) {
            queue<TreeNode *> current_level;

            while (!pre_level.empty()) {
                auto front = pre_level.front();
                pre_level.pop();
                if (!tokens[pos].empty()) {
                   front->left = new TreeNode(stoi(tokens[pos]));
                   current_level.push(front->left);
                }
                pos++;
                if (!tokens[pos].empty()) {
                    front->right = new TreeNode(stoi(tokens[pos]));
                    current_level.push(front->right);
                }
                pos++;
            }

            pre_level.swap(current_level);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

