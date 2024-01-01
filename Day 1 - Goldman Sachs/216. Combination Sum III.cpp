class Solution {
public:
    vector<vector<int>> ans;
    void help(int i, vector<int> &C, int t, vector<int> &sol, int k){
        if(t==0 && k==0){
            ans.push_back(sol);
            return;
        }
        if(t<0 || k<0){
            return;
        }
        if(i==C.size()){
            return;
        }
        // skip the ith element
        help(i+1, C, t, sol, k);

        // Pick the ith element
        sol.push_back(C[i]);
        help(i+1, C, t-C[i], sol, k-1);
        // BT
        sol.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int t) {
        vector<int> C = {1,2,3,4,5,6,7,8,9};
        vector<int> sol;
        help(0, C, t, sol, k);
        return ans;
    }
};
