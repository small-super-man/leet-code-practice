//
// Created by tangchao on 2022/5/30.
//

class Solution {
public:
    string largestNumber(vector<int>& nums) {
       vector<string> nums_str;
       for (auto  &e : nums) {
            nums_str.push_back(to_string(e));
       }
       sort(nums_str.begin(), nums_str.end(), [](const string &one, const string &two){
            int i = 0;
            int limit = min(one.size(), two.size());
            while (i < limit) {
                if (one[i] != two[i]) {
                    break;
                }
                ++i;
            }
            if (i < limit) {
               return one[i] > two[i];
            }

            return one + two > two + one;
       });

       if (nums_str[0] == "0") {
          return "0";
       }

       string result;
       for (auto &e : nums_str) {
          result += e;
       }

       return result;
    }
};
