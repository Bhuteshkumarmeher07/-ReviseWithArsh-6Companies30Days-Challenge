class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // Step 1: Sort
        sort(nums.begin(), nums.end());
        // Step 2: Create ans vector
        vector<int> ans(nums.size());
        // Step 3: Fill ans array
        int i=1;
        int j = nums.size() - 1;

        while(i<nums.size()){
            ans[i] = nums[j];
            j--;
            i+=2;
        }
        // i out of bound chala gaya toh
        i = 0;
        while(i<nums.size()){
            ans[i] = nums[j];
            j--;
            i+=2;
        }
        // Original vector filling 
        for(int i=0; i<nums.size(); i++){
            nums[i] = ans[i];
        }
    }
};
