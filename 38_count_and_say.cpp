//
// Created by tangchao on 2022/5/21.
//

class Solution {
public:
    string countAndSay(int n) {
        if (1 == n) {
           return "1";
        }

        string current_say = "1";
        for (int i = 2; i <= n; ++i) {
            string tmp_say = "";

            char current_char = current_say[0];
            int current_num = 0;
            for (int j = 0; j < current_say.size(); ++j) {
                if (current_char == current_say[j]) {
                   ++current_num;
                } else {
                   tmp_say += to_string(current_num);
                   tmp_say.push_back(current_char);
                   current_char = current_say[j];
                   current_num = 1;
                }
            }
            tmp_say += to_string(current_num);
            tmp_say.push_back(current_char);

            current_say = tmp_say;
        }

        return current_say;
    }
};