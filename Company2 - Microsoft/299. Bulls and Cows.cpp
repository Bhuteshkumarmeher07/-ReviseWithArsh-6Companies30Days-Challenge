class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> map1, map2;

        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                map1[secret[i]]++;
                map2[guess[i]]++;
            }
        }
        // Freq wala section handle kar raha hun
        for(auto it:map1){
            if(map2.find(it.first) != map2.end()){
                cows += min(it.second, map2[it.first]);
            }
        }

        // ans ka structure
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        // then return ans
        return ans;

    }
};
