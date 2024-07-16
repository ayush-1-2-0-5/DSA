class MedianFinder {
 public:
  void addNum(int num) {
    if (maxHeap.empty() || num <= maxHeap.top())
      maxHeap.push(num);
    else
      minHeap.push(num);
    if (maxHeap.size() < minHeap.size())
      maxHeap.push(minHeap.top()), minHeap.pop();
    else if (maxHeap.size() - minHeap.size() > 1)
      minHeap.push(maxHeap.top()), maxHeap.pop();
  }

  double findMedian() {
    if (maxHeap.size() == minHeap.size())
      return (maxHeap.top() + minHeap.top()) / 2.0;
    return maxHeap.top();
  }

 private:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<>> minHeap;
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */