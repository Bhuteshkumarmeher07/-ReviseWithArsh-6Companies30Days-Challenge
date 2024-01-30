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
       
    int countPairs(TreeNode* root, int distance) {
       map<TreeNode*, TreeNode*> mp; // in this map i'm storing every child his parent
            queue<TreeNode*> q;
           q.push(root);
        vector<TreeNode*> vec;// storing leaf node
          while(!q.empty()){
              auto x=q.front(); q.pop();
              if(x->left!=NULL){
                  mp[x->left]=x;
                  q.push(x->left);
              }
              if(x->right!=NULL){
                  mp[x->right]=x;
                  q.push(x->right);
              }
              if(x->left==NULL && x->right==NULL){
                  vec.push_back(x);
              }
          }

        int cnt=0;
// itrating every leaf node 
//and my goal is to pair with every leaf node
         for(auto x:vec){
             queue<pair<TreeNode*, int>> pq;
             pq.push({x, 0}); // in stroing in the form ({node, dist})
                 map<TreeNode*, int> mp1; // it is use for check node are alrady visted or not
               while(!pq.empty()){
                     auto y=pq.front(); pq.pop();
                        auto node=y.first;
                        int dis=y.second;
                           mp1[y.first]++;
//it is checking node is not same and if node is leaf and also checking dist from the start leaf node to this leaf node it should be lessthen or equal to
     if(x!=node && node->left==NULL && node->right==NULL && dis<=distance){ 
                              cnt++;
                            continue;
                        }
      // this condition checking if dist > the given dist 
                   if(dis>=distance){
                       continue;
                   }
                   if(node->left!=NULL && mp1.find(node->left)==mp1.end()){
                       pq.push({node->left,  dis+1});
                   }
                    if( node->right!=NULL && mp1.find(node->right)==mp1.end()){
                       pq.push({node->right,  dis+1});
                   }
           //  checking for parent
                   if(mp.find(node)!=mp.end() && mp1.find(mp[node])==mp1.end()){
                       pq.push({mp[node], dis+1});
                   }
                   
               }
              
         }
          // at last every leaf node paired with another leaf node 2 times
        return cnt/2;
    }
};
