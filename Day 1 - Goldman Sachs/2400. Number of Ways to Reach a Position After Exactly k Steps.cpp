class Solution {
    int mod = 1e9 + 7;
    long long solve(int curr, int endPos, int k, vector<vector<int>>& dp){
        if(k == 0){
            return curr==endPos;
        }
        if(dp[999+curr][k] != -1){
            return dp[999+curr][k];
        }
        long long forw = solve(curr+1,endPos,k-1,dp);
        long long back = solve(curr-1,endPos,k-1,dp);
        return dp[999+curr][k] = (forw+back)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,dp)%mod;
    }
};
// Intuition
// Here in the first read we can conclude that we can either move 1 step forward or 1 step backward, total k times and return the number of ways such that our final position is endPos. This is a classic DP problem, we can also solve it using recursion+memoization.

// Approach
// Recursive Function:
// Base Case: If k is zero then we cannot do any further operations so we need to stop here only and check if we are at endPos or not.

// Recursive Call: We can either move to current + 1 position or current - 1 position, and k will be decremented by 1, since we performed one operation at this stage.

// return the sum of result of both recursive calls.

// Memoization:
// Two variable are changing,i.e, current position and k. So we need to make a 2D DP table. Since we can generate negative numbers, so to handle negative indexes, I saw the constraints. The minimum position we can go is 1-1000 = -999, and maximum position we can go is 1000+1000=2000. So to handle negative indexes we will shift the indes by +999. So I took the size of DP table as 3000 X k, since 2000 will be computed at 2000+999 = 2999.

// Complexity
// Time complexity:
// O(3000*k)

// Space complexity:
// O(3000*k)
