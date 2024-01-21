class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lostCount(100001, -1);
        for(auto match : matches){
            int pWin = match[0];
            int pLost = match[1];
            // by default value is -1
            // if the player is playing, put 0
            if(lostCount[pWin] == -1){
                lostCount[pWin] = 0;
            }
            // If lost, put 1
            if(lostCount[pLost] == -1){
                lostCount[pLost] = 1;
            }
            else{ // If it is lost again, simply increase
                lostCount[pLost]++;
            }
        }

        vector<int> zeroLost, oneLost;
        for(int i=1; i<100001; i++){ // traverse all the keys
            if(lostCount[i] == 0){
                zeroLost.push_back(i);
            }
            else if(lostCount[i] == 1){
                oneLost.push_back(i);
            }
        }
        return {zeroLost, oneLost};
    }
};
