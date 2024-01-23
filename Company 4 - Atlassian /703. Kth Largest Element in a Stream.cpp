class KthLargest {
public:
    int position;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        position = k;
        for(int &num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop(); // min element will be pop out
        }
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > position) pq.pop();
        return pq.top(); 
    }
};
