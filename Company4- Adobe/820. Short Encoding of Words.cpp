class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(), words.end());
        set<string> s2(words.begin(), words.end());

        for(auto parts:s1){
            // time
            for(int i=1; i<parts.size(); i++){
                s2.erase(parts.substr(i));
                // ime
                // me
                // e
            }
        }
        int sum = 0;
        for(auto parts:s2){
            sum += parts.size()+1;
        }
        return sum;
    }
};
