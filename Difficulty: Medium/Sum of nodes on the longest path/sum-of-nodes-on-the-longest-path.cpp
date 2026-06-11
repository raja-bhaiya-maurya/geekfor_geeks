/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  pair<int,int> solve(Node* root){
       if( root==NULL){
            pair<int,int> p= make_pair(0,0);
            
             return p;
        }
       
        
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
    
      int lh= left.first;int ls= left.second;
      int rh= right.first; int rs= right.second;
      int h= max(lh,rh)+1;
      int sum;
    // sum= max(ls,rs)+ root->data;
      
      
      if(lh>rh){
          sum=ls+root->data; 
      }else if(lh<rh){
          sum= rs+root->data;
      }else{
          if(rs>ls){
              sum=rs+root->data;
          }else{
              sum=ls+root->data;
          }
      }
       pair<int,int> a= make_pair(h,sum);
        // a.first=h;
        // a.second = sum;
        return a;
  }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
       pair<int,int>p= solve(root);
       return p.second;
       
      
    }
};