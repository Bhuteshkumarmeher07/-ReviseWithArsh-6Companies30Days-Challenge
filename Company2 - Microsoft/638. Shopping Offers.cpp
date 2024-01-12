class Solution {
public:
    map<vector<int>, int> mp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        if(accumulate(needs.begin(), needs.end(), 0) == 0) return 0;  //sums up all the needs 
        if(mp.find(needs) != mp.end()) return mp[needs];   // If previously calculated results exist for this need array we will return those result
        int cost = 0;
        for(int k = 0; k < price.size(); k++) cost += price[k]*needs[k]; //price with  no special offer
        vector<int> aux = needs; // auxilary array to restore needs after making necessary changes
        for(int i = 0; i < special.size(); i++){
            int j = 0;
            for(j = 0; j < needs.size(); j++) 
                if(needs[j] < special[i][j]) break; 
            if(j < needs.size()) continue; // if there exists a need which is less than what's offered in special offer we will not calculate for that offer
            for(j = 0; j < needs.size(); j++) needs[j]-=special[i][j]; // reducing needs as offer is applied
            cost = min(cost,special[i][needs.size()] + shoppingOffers(price, special, needs));
            needs = aux;
        }
        return mp[aux] = cost;
    }
};
