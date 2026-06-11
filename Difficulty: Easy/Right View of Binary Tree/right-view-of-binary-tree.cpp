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
  void rightView2(Node* root,map<int,int>& m,int lvl){
      
      if(root==NULL) return;
      if(!m.count(lvl)) { m[lvl]=root->data;}
      if(root->right){
          rightView2(root->right,m,lvl+1);
      }
      if(root->left){
          rightView2(root->left,m,lvl+1);
      }
  }
    vector<int> rightView(Node *root) {
        //  code here
      
         vector<int> ans;
        map<int,int> m;//<lvl,data>
          rightView2(root,m,0);

        
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};