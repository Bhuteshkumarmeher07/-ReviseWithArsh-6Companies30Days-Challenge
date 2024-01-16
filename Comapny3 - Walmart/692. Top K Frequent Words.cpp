class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b) { 
        if(a.second == b.second){
            return a.first > b.first;
        }else{
            return a.second < b.second; 
        }
    } 

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        vector<string> result;
        for(auto s : words){
            count[s]++;
        }
        vector<pair<string, int>> checker;
        for(auto it: count){
            checker.push_back(it);
        }
        sort(checker.rbegin(), checker.rend(), cmp);
        for(int i = 0; i < k; i++){
            result.push_back(checker[i].first);
        }

        return result;
    }
};
