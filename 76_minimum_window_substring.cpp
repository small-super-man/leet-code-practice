//
// Created by tangchao on 2022/5/23.
//

class Solution {
public:
    bool isCover(int tt[], int current[]) {
        for (int i = 0; i < 52; ++i) {
            if (tt[i] > current[i]) {
                return false;
            }
        }

        return true;
    }

    bool isEdge(char ch, int tt[], int current[]) {
        int idx = ch >= 'a' && ch <= 'z' ? ch - 'a' + 26 :  ch - 'A';
        return tt[idx] == current[idx];
    }

    string minWindow(string s, string t) {
       int tt[52] = {0};
       for (auto &e : t) {
           if (e >= 'a' && e <= 'z') {
               ++tt[e - 'a' + 26];
           } else {
               ++tt[e - 'A'];
           }
       }

       int min_size = INT_MAX;
       string result = "";

       int start = 0;
       int end = 0;
       int current[52] = {0};
       while (end < s.size()) {
            while (end < s.size() && !isCover(tt, current)) {
                if (s[end] >= 'a' && s[end] <= 'z') {
                    ++current[s[end] - 'a' + 26];
                } else {
                    ++current[s[end] - 'A'];
                }
                ++end;
            }
            if (isCover(tt, current)) {
                while(!isEdge(s[start], tt, current)) {
                    if (s[start] >= 'a' && s[start] <= 'z') {
                        --current[s[start] - 'a' + 26];
                    } else {
                        --current[s[start] - 'A'];
                    }
                    ++start;
                }

                if (end - start < min_size) {
                    min_size = end - start;
                    result = s.substr(start, min_size);
                }

                if (s[start] >= 'a' && s[start] <= 'z') {
                    --current[s[start] - 'a' + 26];
                } else {
                    --current[s[start] - 'A'];
                }
                ++start;
            }
       }

       return result;
    }
};