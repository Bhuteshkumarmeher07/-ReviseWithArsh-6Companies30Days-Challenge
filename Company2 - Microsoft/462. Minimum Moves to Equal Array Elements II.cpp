class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid = n/2;
        int eq=nums[mid];
        int res=0;
        for(auto i:nums){
            res+=abs(eq-i);
        }  
        return res; 
    }
};

// Intuition
// make the array element equal to mid element

// Approach
// sort and get the mid element 
// and than subtract each element from mid elemnet 
// and get the no of time to increment/decrement frequency 
// and add them to our result
