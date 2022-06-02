//
// Created by tangchao on 2022/6/1.
//

class Solution {
public:
    struct Event {
        int pos;
        int index;
        bool isIn;
        Event(int pos_, int index_, bool isIn_) : pos(pos_), index(index_), isIn(isIn_) {}
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int buildings_size = buildings.size();
        vector<bool> is_active(buildings_size, true);
        vector<Event> events;
        for (int i = 0; i < buildings_size; ++i) {
            events.push_back(Event(buildings[i][0], i, true));
            events.push_back(Event(buildings[i][1], i, false));
        }
        sort(events.begin(), events.end(), [](const Event &one, const Event &two) {
            return one.pos < two.pos || (one.pos == two.pos && one.isIn);
        });

        vector<vector<int>> result;
        auto cmp = [&buildings](const int &one, const int &two) {
            return buildings[one][2] < buildings[two][2];
        };
        priority_queue<int, vector<int>, decltype(cmp)> prior_queue(cmp);
        int i = 0;
        int events_size = events.size();
        int prior_idx = -1;
        int prior_h = 0;
        while (i < events_size) {
            int pos = events[i].pos;
            while (i + 1 < events_size && events[i + 1].pos == pos) {
               if (events[i].isIn) {
                    prior_queue.push(events[i].index);
               } else {
                    is_active[events[i].index] = false;
               }
               ++i;
            }
            if (events[i].isIn) {
                prior_queue.push(events[i].index);
            } else {
                is_active[events[i].index] = false;
            }

            while (!prior_queue.empty() && !is_active[prior_queue.top()]) {
                prior_queue.pop();
            }

            if (!prior_queue.empty()) {
                if (buildings[prior_queue.top()][2] != prior_h) {
                    result.push_back(vector<int>({pos, buildings[prior_queue.top()][2]}));
                    prior_h = buildings[prior_queue.top()][2];
                }
            } else {
                result.push_back(vector<int>({pos, 0}));
                prior_h = 0;
            }

            ++i;
        }

        return result;
    }
};
