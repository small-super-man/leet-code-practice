//
// Created by tangchao on 2022/5/29.
//

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         int tokens_size = tokens.size();
         stack<int> st;
         for (int i = 0; i < tokens_size; ++i) {
             if (tokens[i][tokens[i].size() - 1] >= '0' && tokens[i][tokens[i].size() - 1] <= '9') {
                int tmp_num = stoi(tokens[i]);
                st.push(tmp_num);
             } else {
                 int op2 = st.top();
                 st.pop();
                 int op1 = st.top();
                 st.pop();
                 int tmp_res = 0;
                 switch (tokens[i][0]) {
                 case '+':
                     tmp_res = op1 + op2;
                     break;
                 case '-':
                     tmp_res = op1 - op2;
                     break;
                 case '*':
                     tmp_res = op1 * op2;
                     break;
                 case '/':
                     tmp_res = op1 / op2;
                     break;
                 default:
                     break;
                 }
                 st.push(tmp_res);
             }
         }

         return st.top();
    }
};