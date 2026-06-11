/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        queue<Node*> q;
        q.push(root);
        bool isLeftToRight=0;
      
        vector<int> ans;
        while(!q.empty()){
            isLeftToRight=!isLeftToRight;
            vector<int> first(q.size());
            
            for(int i=0;i<first.size();i++){
                Node* temp= q.front();
            q.pop();
             first[i]=(temp->data);
              
            if(temp->left) { q.push(temp->left);}
              
             if(temp->right) {q.push(temp->right);}
              
            }
            
        if(isLeftToRight){
            for(int i=0;i<first.size();i++){
                ans.push_back(first[i]);
            }
                
            }else{
                 for(int i=first.size()-1;i>=0;i--){
                ans.push_back(first[i]);
            }
            }
              
               
          
            
            
            
        }
        return ans;
    }
};