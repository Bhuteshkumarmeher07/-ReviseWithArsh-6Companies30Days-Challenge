class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;

        unordered_map<string, int> m;
        for(int i=0;i<=n-10;i++){
            string str = s.substr(i,10);
            m[str]++;
        }

        for(auto it:m){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
