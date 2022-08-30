//
// Created by tangchao on 2022/6/27.
//

class Solution {
public:
    std::set<std::string> concatenate(const std::set<std::string> &one, const std::set<std::string> &two) {
        std::set<std::string> three;
        for (auto &e : one) {
            for (auto &ee : two) {
                string eee = e + ee;
                three.insert(eee);
            }
        }

        return three;
    }

    vector<string> braceExpansionII(string expression) {
        std::stack<char> op_stack;
        std::stack<std::set<std::string>> str_stack;

        int size = expression.size();
        int i = 0;
        while (i < size) {
            if (',' == expression[i]) {
                while (!op_stack.empty() && (op_stack.top() == ',' || op_stack.top() == '+')) {
                    std::set<std::string> second = str_stack.top();
                    str_stack.pop();
                    std::set<std::string> first = str_stack.top();
                    str_stack.pop();

                    if (op_stack.top() == ',') {
                        first.insert(second.begin(), second.end());
                        str_stack.push(first);
                    } else {
                        std::set<std::string> third = concatenate(first, second);
                        str_stack.push(third);
                    }

                    op_stack.pop();
                }

                op_stack.push(expression[i]);
            } else if ('{' == expression[i]) {
                if (i > 0 && ((expression[i - 1] == '}') || (expression[i - 1] >= 'a' && expression[i - 1] <= 'z'))) {
                    op_stack.push('+');
                }
                op_stack.push('{');
            } else if ('}' == expression[i]) {
                while (!op_stack.empty() && op_stack.top() != '{') {
                    std::set<std::string> second = str_stack.top();
                    str_stack.pop();
                    std::set<std::string> first = str_stack.top();
                    str_stack.pop();

                    if (op_stack.top() == ',') {
                        first.insert(second.begin(), second.end());
                        str_stack.push(first);
                    } else {
                        std::set<std::string> third = concatenate(first, second);
                        str_stack.push(third);
                    }

                    op_stack.pop();
                }

                assert(op_stack.top() == '{');
                op_stack.pop();
            } else {
                if (i > 0 && expression[i - 1] == '}') {
                    op_stack.push('+');
                }

                std::string tmp;
                while (i < size && expression[i] >= 'a' && expression[i] <= 'z') {
                    tmp.push_back(expression[i]);
                    ++i;
                }
                std::set<std::string> tmp_set;
                tmp_set.insert(tmp);
                str_stack.push(tmp_set);
                --i;
            }

            ++i;
        }

        while (!op_stack.empty()) {
            std::set<std::string> second = str_stack.top();
            str_stack.pop();
            std::set<std::string> first = str_stack.top();
            str_stack.pop();

            if (op_stack.top() == ',') {
                first.insert(second.begin(), second.end());
                str_stack.push(first);
            } else {
                std::set<std::string> third = concatenate(first, second);
                str_stack.push(third);
            }

            op_stack.pop();
        }

        return vector<string>(str_stack.top().begin(), str_stack.top().end());
    }
};