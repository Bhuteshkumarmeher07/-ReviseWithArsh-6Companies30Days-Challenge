class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) { 
        int ans = 0;    
        int i= 0; 
        //int n = nums.size(); 
        
        map<int,int> map; 
        
        for(int j=0; j<nums.size(); j++)
        { 
            map[nums[j]]++; 
            while(map[nums[j]] > k)
            { 
                map[nums[i]]--; 
                if(map[nums[i]] == 0)map.erase(nums[i]); 
                i++; 
            }             
            ans = max(ans, j - i + 1); 
        } 
        return ans; 
    } 
};
