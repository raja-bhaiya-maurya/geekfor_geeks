/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
        int solve(Node* root,vector<int> &v, int k,int node){
            if(root == NULL){
                return -1;
            }
            
            v.push_back(root->data);
             if(root->data==node){
               int idx= v.size()-1-k;
               if(idx>=0)return v[idx];
                else return -1;
                
            }
           int left= solve(root->left,v,k,node);
           if(left!=-1) return left;
           int right= solve(root->right,v,k,node);
           if(right!= -1) return right;
           
         
           
              v.pop_back();
              return -1;
            
            
        }
    int kthAncestor(Node *root, int k, int node) {
        // code here
        if(root==NULL) return -1;
        vector<int> v;
        int ans=solve(root,v,k,node);
        return ans;
        
    }
};
