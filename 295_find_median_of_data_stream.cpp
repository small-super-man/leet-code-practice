//
// Created by tangchao on 2022/6/4.
//

class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (!minHeap.empty() && minHeap.top() <= num) {
            minHeap.push(num);
        } else  {
            maxHeap.push(num);
        }

        while (minHeap.size() < maxHeap.size()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }

        while (minHeap.size() > maxHeap.size() + 1) {
            auto top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return static_cast<double>(minHeap.top() + maxHeap.top()) / 2;
        }
    }

private:
    priority_queue<int, vector<int>, std::less<int>> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */