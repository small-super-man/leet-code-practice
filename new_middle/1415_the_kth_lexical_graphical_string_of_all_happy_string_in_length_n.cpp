//
// Created by tangchao on 2022/6/30.
//

class Solution {
public:
    void _getHappyString(string &currentStr, int n, int k, int &index, string &result) {
        if (currentStr.size() >= n) {
           ++index;
           if (index == k) {
               result = currentStr;
           }
           return;
        }

        for (int i = 0; i < 3; ++i) {
            char ch = i + 'a';
            if (currentStr.empty() || currentStr[currentStr.size() - 1] != ch) {
                currentStr.push_back(ch);
                _getHappyString(currentStr, n, k, index, result);
                currentStr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string current;
        string result;
        int idx = 0;
        _getHappyString(current, n, k, idx, result);
        return result;
    }
};