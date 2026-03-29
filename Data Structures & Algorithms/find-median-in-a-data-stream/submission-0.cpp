class MedianFinder {
private:
    priority_queue<int> maxHeap; //左側　

    priority_queue<int, vector<int>, greater<int>> minHeap;//右側
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 != 0) {
            return maxHeap.top();
        }else{
            return (double) (maxHeap.top() + minHeap.top()) / 2; 
        }
    }
};
