//
// Created by tangchao on 2022/5/28.
//

class LRUCache {
public:
    // int --> list::iterator
    LRUCache(int capacity) {
       this->_capacity = capacity;
    }

    int get(int key) {
        auto iter = _innerMap.find(key);
        if (iter == _innerMap.end()) {
            return -1;
        }

        pair<int, int> current_pair = *(iter->second);
        _innerList.erase(iter->second);

        auto current_list_iter = _innerList.insert(_innerList.begin(), current_pair);
        iter->second = current_list_iter;

        return current_list_iter->second;
    }

    void put(int key, int value) {
        auto iter = _innerMap.find(key);
        if (iter != _innerMap.end()) {
            pair<int, int> current_pair = *(iter->second);
            _innerList.erase(iter->second);
            current_pair.second = value;

            auto current_list_iter = _innerList.insert(_innerList.begin(), current_pair);
            iter->second = current_list_iter;
        } else {
            if (_innerList.size() >= _capacity) {
                _innerMap.erase(_innerList.back().first);
                _innerList.pop_back();
            }

            auto current_list_iterator = _innerList.insert(_innerList.begin(), make_pair(key, value));
            _innerMap.insert({key, current_list_iterator});
        }
    }

private:
    typedef list<pair<int, int>>::iterator innerIterator;
    list<pair<int, int>> _innerList;
    unordered_map<int, innerIterator> _innerMap;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */