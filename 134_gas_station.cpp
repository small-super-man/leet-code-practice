//
// Created by tangchao on 2022/5/26.
//

class Solution {
public:
    // i-1 --> i
    // remain(i - 1) = gas(i - 1) + remain(i - 2) - cost(i - 2)
    // remain(i - 1) >= cost[i - 1]
    // gas(i - 1) -  cost(i - 2) + remain(i - 2) >= cost(i - 1)
    // gas(i - 1) + remain(i - 2) >= cost(i - 2) + cost(i - 1)
    // v(i) = gas(i) - cost(i)
    // sum(v(i)) >= 0 --> can reach (i + 1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num_size = gas.size();
        assert(num_size == cost.size());
        vector<int> diff(num_size, 0);
        for (int i = 0; i < num_size; ++i) {
            diff[i] = gas[i] - cost[i];
        }

        int start = 0;
        int end = (start + 1) % num_size;
        int sum = diff[0];
        while (true) {
            while (end != start && sum >= 0) {
                sum += diff[end];
                end = (end + 1) % num_size;
            }

            if (end == start && sum >= 0) {
                return start;
            }

            //sum <  0
            if (end > start) {
                start = end;
                sum = diff[start];
                end = (start + 1) % num_size;
            } else {
                return -1;
            }
        }

        return  -1;
    }
};