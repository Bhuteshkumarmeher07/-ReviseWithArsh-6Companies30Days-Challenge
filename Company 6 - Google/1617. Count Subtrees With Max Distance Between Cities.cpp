class Solution {
    int solve(int subtree, vector<vector<int>>&dist, int n){
        int countNode = 0, countEdges = 0, maxDist = 0;
        for(int i=0; i<n; i++){
            if(((subtree>>i) &1) == 0) continue;

            countNode++;
            for(int j=i+1; j<n; j++){
                if(((subtree>>j)&1) == 0) continue;
                if(dist[i][j] == 1) countEdges++;
                maxDist = max(maxDist, dist[i][j]);
            }
        }
        if(countNode == countEdges + 1){
            return maxDist;
        }
        return -1;
    }
public:    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> v(n-1, 0); // no of subtrees for each distance
        vector<vector<int>> dist(15, vector<int>(15, INT_MAX)); // min dist betn each node = 15
        // iterate over the vector edges
        for(auto temp : edges){
            dist[temp[0]-1][temp[1]-1] = 1;
            dist[temp[1]-1][temp[0]-1] = 1;
            // vice versa, since it is a bi directional tree

        }
        // Using Floyd warshaw algo
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[j][k] == INT_MAX) continue;
                    dist[i][j] = dist[j][i] = min({dist[i][j], dist[j][i], dist[i][k] + dist[k][j]});
                    // min dist betwn any two graph will be equal since it is bidirectional tree


                }
            }
        }
        // we iterate over all the subset
        for(int i=0; i<(1<<n); i++){
            int ans = solve(i, dist, n);
            if(ans > 0){
                v[ans-1]++;
            }
        }
        return v;
    }
};
