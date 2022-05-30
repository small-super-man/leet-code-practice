//
// Created by tangchao on 2022/5/29.
//

class Solution {
public:
    struct Line {
      double k;
      double b;
      bool flag;
      Line(double _k, double _b, bool _flag) : k(_k), b(_b), flag(_flag) {}

      bool operator == (const Line &other) {
          return fabs(k - other.k) <= 1e-8 && fabs(b - other.b) <= 1e-8 && flag == other.flag;
      }
    };

    int maxPoints(vector<vector<int>>& points) {
        int points_size = points.size();
        vector<Line> lines;
        for (int i = 0; i < points_size; ++i) {
            for (int j = i + 1; j < points_size; ++j) {
                if (points[i][0] == points[j][0]) {
                    lines.push_back(Line(0, points[i][0], true));
                } else {
                    double kk = double(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    double bb = points[i][1] - kk * points[i][0];
                    lines.push_back(Line(kk, bb, false));
                }
            }
        }

        sort(lines.begin(), lines.end(), [](const Line &one, const Line &two) {
            return (one.flag && two.flag && one.b < two.b) || (one.flag && !two.flag) || (!one.flag && !two.flag && one.k < two.k) || (!one.flag && !two.flag && fabs(two.k - one.k) <= 1e-8 && one.b < two.b);
        });

        for (int i = 0; i < lines.size(); ++i) {
            cerr << lines[i].k << ", " << lines[i].b << ", " << lines[i].flag << endl;
        }

        int max_num = 0;
        int current_num = 0;
        for (int i = 0; i < lines.size(); ++i) {
            if (!current_num) {
               current_num = 1;
            } else {
               if (lines[i] == lines[i - 1]) {
                   ++current_num;
               } else {
                   if (max_num < current_num) {
                      max_num = current_num;
                   }
                   current_num = 1;
               }
            }
        }
        if (max_num < current_num) {
           max_num = current_num;
        }

        int n = 1;
        while (true) {
            int sum = (n * (n - 1)) / 2;
            if (sum >= max_num) {
                break;
            }
            ++n;
        }

        return n;
    }
};