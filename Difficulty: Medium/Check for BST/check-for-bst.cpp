/*
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
    bool solve(Node* root,int min, int max){
        if(root==NULL){
            return true;
        }
      if(root->data<=min || root->data>=max){
          return false;
      } 
        bool left=solve(root->left,min,root->data);
       
        
        bool right= solve(root->right,root->data,max);
    
       
        if(left && right){
            return true;
        }
        else return false;
        
    
    }
  public:
    bool isBST(Node* root) {
        // code here
        int min= INT_MIN;
        int max= INT_MAX;
        bool ans=solve(root,min,max);
        return ans;
    }
};