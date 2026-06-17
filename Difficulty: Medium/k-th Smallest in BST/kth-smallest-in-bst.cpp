/*
Definition for Node
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
  
   void solve1(Node* root, vector<int> &inorder){
       
       if (root== NULL) return;
       
        solve1( root->left,inorder);
        
        inorder.push_back(root->data);
      
        solve1( root->right,inorder);

   }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int>inorder;
        solve1(root,inorder);
        int ans;
        if(k-1<0||k-1>=inorder.size()){
             ans= -1;
        }
         else ans= inorder[k-1];
        return ans;
    }
};