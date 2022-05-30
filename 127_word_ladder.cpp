//
// Created by tangchao on 2022/5/26.
//

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> idx_map;
        for (int i = 0; i < wordList.size(); ++i) {
            idx_map.insert({wordList[i], i});
        }

        if (0 == idx_map.count(endWord)) {
            return 0;
        }

        if (beginWord == endWord) {
           return 1;
        }

        if (0 == idx_map.count(beginWord)) {
            idx_map.insert({beginWord, wordList.size()});
            wordList.push_back(beginWord);
        }

        vector<vector<int>> graph;
        for (int i = 0; i < wordList.size(); ++i) {
            vector<int> sub_list;
            for (int j = 0; j < wordList[i].size(); ++j) {
                for (int k = 0; k < 26; ++k) {
                    char ch = 'a' + k;
                    if (ch != wordList[i][j]) {
                        string tmp_word = wordList[i];
                        tmp_word[j] = ch;
                        auto iter = idx_map.find(tmp_word);
                        if (iter != idx_map.end()) {
                            sub_list.push_back(iter->second);
                        }
                    }
                }
            }
            graph.push_back(std::move(sub_list));
        }

        int begin_idx = idx_map[beginWord];
        int end_idx = idx_map[endWord];

        //bfs
        queue<int> bfs_queue;
        bfs_queue.push(begin_idx);
        int level = 1;
        int current_queue_size = 1;
        vector<bool> visited(wordList.size(), false);
        visited[begin_idx] = true;
        while (!bfs_queue.empty()) {
            int subsequent_queue_size = 0;
            for (int i = 0; i < current_queue_size; ++i) {
               auto front = bfs_queue.front();
               bfs_queue.pop();
               for (auto j = 0; j < graph[front].size(); ++j) {
                    if (!visited[graph[front][j]]) {
                        if (graph[front][j] == end_idx) {
                            return level + 1;
                        }
                        visited[graph[front][j]] = true;
                        bfs_queue.push(graph[front][j]);
                        ++subsequent_queue_size;
                    }
               }
            }
            current_queue_size = subsequent_queue_size;
            ++level;
        }

        return 0;
    }
};