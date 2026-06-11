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

	vector<vector<int>> verticalOrder(Node *root) {
		// code here
		vector<vector<int>> ans;
		
		if(root==NULL)return ans;
		
		map<int,vector<int>  > m;
	//  map<HD,map<lvl,vector<data> > > m;
		queue <pair<Node*,pair<int,int> > > q;
	//	queue pair<root,pair<HD,lvl> > q;
		q.push(make_pair(root,make_pair(0,0)));
		
		while(!q.empty()){
		    pair<Node*,pair<int,int> > temp= q.front();
		    q.pop();
		    
		    //extract
		    Node* front = temp.first;
		    int hd= temp.second.first;
		    int lvl= temp.second.second;
		    
		    m[hd].push_back(front->data);
		    
		    if(front->left){
		        q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));
		        
		    }
		    if(front->right){
		        q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));
	        
		    }
		    
		}
		for(auto i: m){
		    
		        ans.push_back(i.second);
		    
		}
		
	
		return ans;
	}
};
