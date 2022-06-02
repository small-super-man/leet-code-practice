//
// Created by tangchao on 2022/6/2.
//

class Solution {
public:
    int _nextToken(const string &s, int startIdx, string &outToken) {
       outToken.clear();
       while (startIdx < s.size() && s[startIdx] == ' ') {
          ++startIdx;
       }

       if (startIdx >= s.size()) {
          return -1;
       }

       if (s[startIdx] >= '0' && s[startIdx] <= '9') {
            while (startIdx < s.size() && s[startIdx] >= '0' && s[startIdx] <= '9') {
                outToken.push_back(s[startIdx++]);
            }
       } else {
            assert(s[startIdx] == '+' || s[startIdx] == '-' || s[startIdx] == '*' || s[startIdx] == '/');
            outToken.push_back(s[startIdx++]);
       }

       return startIdx;
    }

    int opFunc(int opNum1, int opNum2, char op) {
        switch (op) {
        case '+':
            return opNum1 + opNum2;
        case '-':
            return opNum1 - opNum2;
        case '*':
            return opNum1 * opNum2;
        case '/':
            return opNum1 / opNum2;
        default:
            assert(false);
        }
    }

    int calculate(string s) {
        int s_size = s.size();
        stack<int> num_stack;
        stack<char> op_stack;
        int idx = 0;
        string token;
        while (idx < s_size) {
            idx = _nextToken(s, idx, token);
            if (idx == -1) {
               break;
            }

            if (token[0] >= '0' && token[0] <= '9') {
                num_stack.push(stoi(token));
            } else {
                switch(token[0]) {
                case '+':
                case '-':
                    while (!op_stack.empty()) {
                        char op = op_stack.top();
                        op_stack.pop();

                        int op_num2 = num_stack.top();
                        num_stack.pop();
                        int op_num1 = num_stack.top();
                        num_stack.pop();

                        int tmp = opFunc(op_num1, op_num2, op);

                        num_stack.push(tmp);
                    }
                    break;
                case '*':
                case '/':
                    while (!op_stack.empty() && (op_stack.top() == '*'  || op_stack.top() == '/')) {
                        char op = op_stack.top();
                        op_stack.pop();

                        int op_num2 = num_stack.top();
                        num_stack.pop();
                        int op_num1 = num_stack.top();
                        num_stack.pop();

                        int tmp = opFunc(op_num1, op_num2, op);

                        num_stack.push(tmp);
                    }
                    break;
                default:
                    break;
                }
                op_stack.push(token[0]);
            }
        }

        while (!op_stack.empty()) {
            char op = op_stack.top();
            op_stack.pop();

            int op_num2 = num_stack.top();
            num_stack.pop();
            int op_num1 = num_stack.top();
            num_stack.pop();

            int tmp = opFunc(op_num1, op_num2, op);

            num_stack.push(tmp);
        }

        return num_stack.top();
    }
};