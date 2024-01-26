class Solution {
private:
    struct pair {
        string s;
        int index;
        pair(string s, int index) : s(s), index(index) {}
    };    
public:
    // Method 1 : Radix Sort
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries){
        unordered_map<int, vector<pair>> map;

        for(int i=0; i<nums.size(); i++){
            string str = nums[i];
            int n = str.length();
            int l = n;

            for(int j=0; j<n; j++){
                map[l].push_back(pair(str.substr(j), i));
                l--;
            }
        }
        vector<int> ans(queries.size());
        int idx = 0;
        for (vector<int>& query : queries) {
            int kthElement = query[0];
            int key = query[1];
            vector<pair>& list = map[key];
            sort(list.begin(), list.end(), [](const pair& p1, const pair& p2) {
                if (p1.s == p2.s)
                    return p1.index < p2.index;
                return p1.s < p2.s;
            });
            ans[idx++] = list[kthElement - 1].index;
        }
        return ans;        
    }
};

    // //Method 1 : Using sorting
    // vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
    //     vector<int> ans;
    //     for(auto q : queries){
    //         int k = q[0], t =  q[1];
    //         vector<pair<string,int>> str;
    //         int n = nums[0].size(), i = 0;
    //         for(auto &it : nums){
    //             if(n == t) str.push_back({it,i++});
    //             else str.push_back({it.substr(n-t),i++});
    //         }
    //         sort(str.begin(),str.end());
    //         ans.push_back(str[k-1].second);
    //     }
    //     return ans;
    // }
