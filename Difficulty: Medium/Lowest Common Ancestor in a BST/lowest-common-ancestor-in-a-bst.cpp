/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void findPath(Node* root ,Node* node,  vector<Node*> & vector,bool &turn){
      if( root==NULL) return;
       vector.push_back(root);;
      findPath(root->left,node,vector,turn);
      findPath(root->right,node,vector,turn);
      if(root->data==node->data){
        
          turn =1;
      }
      if(turn==0)
     { vector.pop_back();}

  }
  
  Node* findAncestor(vector<Node*> &v1, vector<Node*> & v2){
      int size1= v1.size()-1;
      int size2=v2.size()-1;
     int i=0,j=0;
      while(i<=size1 && j<=size2){
          if(v1[i]!= v2[j]){
              return v1[i-1];
          }
          i++;j++;    
          }
          
         return v1[i-1];
  }
  
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        vector<Node*> v1,v2;bool turn =0;
        findPath(root,n1,v1,turn);
        turn=0;
        findPath(root,n2,v2,turn);
        Node* ans=findAncestor(v1,v2);
        return ans;
        
        
    }
};