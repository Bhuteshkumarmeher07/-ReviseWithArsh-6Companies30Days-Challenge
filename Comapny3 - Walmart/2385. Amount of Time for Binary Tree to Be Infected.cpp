/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode* curr){
        // base case 
        if(curr==NULL) return;
        //
        if(parent != -1){ // curr ka parent
           adj[curr->val].push_back(parent);
        }
        if(curr->left){
            adj[curr->val].push_back(curr->left->val);
        }
        if(curr->right){
            adj[curr->val].push_back(curr->right->val);
        }        
        makeGraph(adj, curr->val, curr-> left);
        makeGraph(adj, curr->val, curr-> right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makeGraph(adj, -1, root);

        // Apply BFS from start
        queue<int> que;
        unordered_set<int> visited;
        que.push(start);
        visited.insert(start);
        int minutes = 0;
        while(!que.empty()){
            int n = que.size(); // curr level size
            while(n--){
                int curr = que.front();
                que.pop();
                for(int &nbr : adj[curr]){
                    if(visited.find(nbr) == visited.end()){
                        que.push(nbr);
                        visited.insert(nbr);
                    }
                }
            }
            minutes++;
        }
        return minutes-1;
    }
    
};
