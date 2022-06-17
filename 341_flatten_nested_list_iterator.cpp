//
// Created by tangchao on 2022/6/7.
//

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        currentList = &nestedList;
        currentIdx = 0;
    }

    int next() {
        assert(currentIdx < currentList->size() && currentList->at(currentIdx).isInteger());
        int res = currentList->at(currentIdx).getInteger();
        ++currentIdx;
        return res;
    }

    bool hasNext() {
        do {
            while (!innerStack.empty() && currentIdx >= currentList->size()) {
                auto top = innerStack.top();
                innerStack.pop();
                currentList = top.first;
                currentIdx = top.second + 1;
            }

            while (currentIdx < currentList->size() && !currentList->at(currentIdx).isInteger()) {
                auto tmp_list = &(currentList->at(currentIdx).getList());
                innserStack.push({currentList, currentIdx});
                currentList = tmp_list;
                currentIdx = 0;
            }

            if (currentIdx < currentList->size()) {
                return true;
            }
        } while (!innerStack.empty());

        return false;
    }
private:
    stack<pair<vector<NestedInteger> *, int>> innerStack;
    vector<NestedInteger> *currentList;
    int currentIdx;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */