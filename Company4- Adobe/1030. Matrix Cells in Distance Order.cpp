class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int x=abs(i-rCenter);
                int y=abs(j-cCenter);
                ans.push_back({x+y,i,j});
            }
        }
        sort(ans.begin(),ans.end());
        
        vector<vector<int>>anss;
        for(int i=0;i<ans.size();i++){
            anss.push_back({ans[i][1],ans[i][2]});
        }

        return anss;
    }
}; // TC - > O(n^2)
