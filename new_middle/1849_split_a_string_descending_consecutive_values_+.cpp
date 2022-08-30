//
// Created by tangchao on 2022/7/5.
//
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    //"050043"
    // although 100% time percentile, still need more thinking
    bool splitString(string s) {
        int s_size = s.size();
        int i = 0;
        while (i < s_size && s[i] == '0') {
            ++i;
        }

        if (i >= s_size - 1) {
            return false;
        }

        long long first_value = 0;
        for (int j = i; j < s_size - 1; ++j) {
            first_value = first_value * 10 + (s[j] - '0');
            if (first_value >= 10000000000) {
               break;
            }


            int k = j + 1;
            long long next_value = first_value - 1;
            long long tmp = 0;
            while (k < s_size) {
                tmp = 0;
                do {
                    tmp = tmp * 10 + s[k] - '0';
                    ++k;
                } while(k < s_size && tmp != next_value);

                if (tmp == next_value && next_value == 0) {
                   while (k < s_size && s[k] == '0') {
                     ++k;
                   }
                }

                if (tmp == next_value && k < s_size) {
                    next_value = tmp - 1;
                }
            }

            if (tmp == next_value)  {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char **argv) {
    Solution solve;

    solve.splitString(std::string("050043"));

    return 0;
}

