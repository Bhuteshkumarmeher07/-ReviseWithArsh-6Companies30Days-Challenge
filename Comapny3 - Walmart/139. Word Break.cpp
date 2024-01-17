class Solution {
public:
    int dp[301];
    int solveUsingMemoization(int i, string s, set<string>& wordDict){
        if(i == s.size()){
            return 1;
        }
        string temp;
        int n = s.size();
        if(dp[i] != -1){
            return dp[i];
        }
        for(int j=i; j<n; j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                if(solveUsingMemoization(j+1, s, wordDict)){
                    return dp[i] = 1;
                }
            }
        }
        return dp[i] = 0;
    }
    int solveUsingRecursion(int i, string s, set<string>& wordDict){
        if(i == s.size()){
            return 1;
        }
        string temp;
        int n = s.size();
        for(int j=i; j<n; j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                if(solveUsingRecursion(j+1, s, wordDict)){
                    return 1;
                }
            }
        }
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto a:wordDict){
            st.insert(a);
        }
        // return solveUsingRecursion(0, s, st);

        // MEMO
        memset(dp, -1, sizeof dp);
        return solveUsingMemoization(0,s,st);
    }
};
