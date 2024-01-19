class Solution {
public:
    int mod = 1e9 + 7;
    int dp[15][15][1 << 14];
    int helper(int ind,int prev_ind,int n,int mask,vector<int>& nums){
        if(ind == n)
            return 1;
        if(dp[ind][prev_ind][mask] != -1)
            return dp[ind][prev_ind][mask];
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!(mask & (1 << i))){
                if(ind == 0 || (nums[prev_ind] % nums[i] == 0) || (nums[i] % nums[prev_ind] == 0))
                    ans = (ans + helper(ind+1,i,n,mask | (1 << i),nums)) % mod;
            }
        }
        return dp[ind][prev_ind][mask] = ans;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,n,0,nums);
    }
};
