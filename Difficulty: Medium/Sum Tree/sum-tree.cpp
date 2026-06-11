/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  
    int sum(Node* root){
        if(root==NULL){
            return 0;
        }
        
        int left=sum(root->left);
        int right= sum(root->right);
         if(root->left==NULL && root->right==NULL){
            return root->data;
        } else if(root->data== left+right){
            return 2*root->data;
        }
        
        else return INT_MAX;
    }
    bool isSumTree(Node* root) {
        // Your code here
        
        if(root==NULL){
            return 0;
        }
        int val=sum(root);
        if(val==2*root->data) return true;
        else return false;
          
    }
};