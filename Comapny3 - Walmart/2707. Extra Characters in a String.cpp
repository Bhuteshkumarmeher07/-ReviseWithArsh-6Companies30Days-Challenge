class Solution {
public:
    vector<int> dp; // create dp vector
    int n;
    int solve(int i,string s, vector<string>& dictionary ){
        // base case
        if(i==n) return 0;
        // Step 3: check ans already hai ya nahi
        if(dp[i] != -1){
            return dp[i];
        }

        int ans = n;
        // Step 2:
        for(string& w : dictionary){
            int wLen = w.size();
            if(i+wLen <= s.size() && s.substr(i, wLen) == w){
                int leftLetter = solve(i+wLen, s, dictionary);
                ans = min(ans,leftLetter);
            }
        }
        int noWord = 1 + solve(i+1, s, dictionary);
        ans = min(ans, noWord);
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        dp.assign(n, -1);
        return solve(0, s, dictionary);
    }
};
