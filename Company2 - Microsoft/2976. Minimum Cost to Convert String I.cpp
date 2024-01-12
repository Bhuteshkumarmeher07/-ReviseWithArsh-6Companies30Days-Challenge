#define ll long long 
class Solution { 
public: 
    map<char,map<char,ll>>mmap; 
    ll dist[200][200]; 
    
    void floydWarshall(){ 
        char i, j, k; 
        for (k = 'a'; k <= 'z'; k++) { 
            for (i = 'a'; i <= 'z'; i++) { 
                for (j = 'a'; j <= 'z'; j++) { 
                    if ((dist[k][j] < INT_MAX && dist[i][k] < INT_MAX) && dist[i][j] > (dist[i][k] + dist[k][j])) 
                    {
                         dist[i][j] = dist[i][k] + dist[k][j]; 
                    }
                } 
            } 
        } 
    } 
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {      
        for(int i=0; i<200;i++)
        { 
            for(int j=0;j<200;j++)
            { 
                dist[i][j]= INT_MAX; 
            } 
        } 
        for(int i=0;i<original.size(); i++){ 
            dist[original[i]][changed[i]] = min(dist[original[i]][changed[i]],(ll)cost[i]); 
        } 
        floydWarshall(); 
        long long solution = 0; 
        for(int i=0; i<source.length(); i++){ 
            if(source[i] == target[i])
                continue; 
            if(dist[source[i]][target[i]] == INT_MAX)
                return -1; 
            else
                solution += (dist[source[i]][target[i]]); 
        } 
        return solution;        
    } 
};
