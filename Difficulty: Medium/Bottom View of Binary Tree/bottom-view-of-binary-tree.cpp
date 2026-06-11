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
    vector<int> bottomView(Node *root) {
        // code here
         vector<int> ans;
        map<int,int> m;//<HD,data>
        queue< pair<Node*,int>> q;//<root,HD>
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> temp= q.front();
            q.pop();
            
            Node* front= temp.first;
            int hd= temp.second;
            
            m[hd]=front->data;
          
          if(front->left){
              q.push(make_pair(front->left,hd-1));
          }
           if(front->right){
              q.push(make_pair(front->right,hd+1));
          }
        }
        for(auto i:m){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};