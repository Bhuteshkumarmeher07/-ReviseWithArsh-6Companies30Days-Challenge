class Solution {
public:
    int solve(vector<int> &arr, int n, int k){
        priority_queue<pair<int,int>> maxHeap;
        maxHeap.push({arr[0], 0});
        int ans = arr[0];

        for(int i=1; i<n; i++){
            while(i-maxHeap.top().second > k){
                maxHeap.pop();
            }
            int sum = max(0, maxHeap.top().first) + arr[i];
            ans = max(ans, sum);
            maxHeap.push({sum, i});
        }
        return ans;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(nums, n, k);
    }
};
