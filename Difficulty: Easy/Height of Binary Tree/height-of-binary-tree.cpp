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
*/int h(Node* root){
     if (root==NULL) return 0;
      
     int lefth =h(root->left);
     int righth= h(root->right);
     
      int ans= max(lefth , righth)+1 ;
      return ans;
}


class Solution {
  public:
    int height(Node* root) {
        if(root==NULL)return -1;
        // code here
        int ans=0;
      ans= h(root);
      return ans-1;
    } 
    
};