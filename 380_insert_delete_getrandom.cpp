//
// Created by tangchao on 2022/6/8.
//

class RandomizedSet {
public:
    RandomizedSet() : _randomEngine(time(nullptr)){
        _idx = 0;
    }

    bool insert(int val) {
        if (_map.count(val)) {
            return false;
        }

        if (_idx < _vec.size()) {
            _vec[_idx] = val;
        } else {
            _vec.push_back(val);
        }

        _map.insert({val, _idx});

        ++_idx;

        return true;
    }

    bool remove(int val) {
        auto iter = _map.find(val);
        if (iter == _map.end()) {
            return false;
        }

        int loc = iter->second;
        --_idx;
        _map[_vec[_idx]] = loc;
        swap(_vec[_idx], _vec[loc]);
        _map.erase(val);

        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> uniform_dist(0, _idx - 1);
        return _vec[uniform_dist(_randomEngine)];
    }

private:
    int _idx;
    int vector<int> _vec;
    unordered_map<int, int>  _map;
    default_random_engine _randomEngine;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */