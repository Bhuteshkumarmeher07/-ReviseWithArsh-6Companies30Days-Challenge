class Solution {
public:
    int countCollisions(string directions) {
        string s = directions;
        vector<pair<char,int>> v;
        for(int i=0; i<s.size();i++){
            int c = 1;
            while(i+1 < s.size() && s[i] == s[i+1]){
                i++, c++;
            }
            v.push_back({s[i], c});
        }
        int ans = 0;
        for(int i=0; i<v.size()-1; i++){
            if(v[i].first == 'R' && v[i+1].first == 'L'){
                ans+=v[i].second + v[i+1].second;
            }
            else if(v[i].first == 'S' && v[i+1].first == 'L'){
                ans+=v[i+1].second;
            }
            else if(v[i].first == 'R' && v[i+1].first == 'S'){
                ans+=v[i].second;
            }
        }
        return ans;
    }
};
