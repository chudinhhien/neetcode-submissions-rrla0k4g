class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;

    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;

        for(int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > _k) pq.pop();

        return pq.top();
    }
};
