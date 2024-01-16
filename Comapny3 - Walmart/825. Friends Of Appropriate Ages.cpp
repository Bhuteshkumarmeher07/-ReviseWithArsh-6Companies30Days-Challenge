class Solution {
public:
    bool condition(int a, int b){
        return !(b <= 0.5*a+7 || b > a || b > 100 && a < 100);
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> count;
        for(int &age : ages){
            count[age]++;
        }
        int request = 0;
        for(auto &a : count){
            for(auto &b : count){
                if(condition(a.first, b.first)){
                    request += a.second * (b.second - (a.first == b.first ? 1 : 0));
                }
            }
        }
        return request;
    }
};
