//
// Created by tangchao on 2022/6/28.
//

class Solution {
public:
    bool can(const vector<int> &need, const vector<int> &count) {
        for (int i = 0; i < 26; ++i) {
            if (need[i] > count[i]) {
                return false;
            }
        }
        return true;
    }

    bool alloc(const vector<int> &need, vector<int> &count) {
        for (int i = 0; i < 26; ++i) {
            count[i] -= need[i];
        }
    }

    bool dealloc(const vector<int> &need, vector<int> &count) {
        for (int i = 0; i < 26; ++i) {
            count[i] += need[i];
        }
    }

    int _maxScore(const vector<vector<int>> &needCounts, const vector<int> &wordsScore, vector<int> &count, int idx) {
       if (idx >= needCounts.size()) {
          return 0;
       }

       int score_hash_idx = 0;
       if (can(needCounts[idx], count)) {
          score_hash_idx = wordsScore[idx];
          alloc(needCounts[idx], count);
          score_hash_idx += _maxScore(needCounts, wordsScore, count, idx + 1);
          dealloc(needCounts[idx], count);
       }

       int score_not_hash_idx = _maxScore(needCounts, wordsScore, count,  idx + 1);

       return max(score_hash_idx, score_not_hash_idx);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<vector<int>> words_need_count;
        vector<int> words_score;
        for (auto &e : words) {
            vector<int> one_count(26, 0);
            int one_score = 0;

            for (auto &ee : e) {
                int idx = ee - 'a';
               ++one_count[idx];
               one_score += score[idx];
            }

            words_need_count.push_back(one_count);
            words_score.push_back(one_score);
        }

       vector<int> count(26, 0);
       for (auto &e : letters) {
            ++count[e - 'a'];
       }

       // 限制
       // (1) 选中的单词集合 <= count
       // (2) 所有满足条件(1)的集合中总分数最大的集合

       int result = _maxScore(words_need_count, words_score, count, 0);
       return result;
    }
};