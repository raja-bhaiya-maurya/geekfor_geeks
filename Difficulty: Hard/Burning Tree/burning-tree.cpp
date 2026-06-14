/*
class Node {
	public:
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
	Node* createMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
		
		Node* res;
	
		queue<Node*> q;
		q.push(root);
		nodeToParent[root] = NULL;
		while (!q.empty()) {
			Node* front = q.front();
				if (front->data == target) {
			res = front;
		}
			q.pop();
			
			if (front->left) {
				q.push(front->left);
				nodeToParent[front->left] = front;
			}
			if (front->right) {
				q.push(front->right);
				nodeToParent[front->right] = front;
			}
			
		}
		
		return res;
	}
	
	void solve (Node* root, map<Node*, Node*> nodeToParent, int& timex) {
		if(root==NULL){
		    return;
		}
		map <Node*, bool> visited;
		queue<Node*> q;
		
		q.push(root);
		visited[root]=1;
		while(!q.empty()){
		     int flag=0;
		     int size=q.size();
		    for(int i= size-1;i>=0;i--){
		        
		    Node* front = q.front();
		    
		  
		    q.pop();
		        if(front->left && ! visited.count(front->left)){
		            q.push(front->left);
		            flag=1;
		            visited[front->left]=1;
		            
		        }
		        
		        if(front->right && ! visited.count(front->right)){
		            q.push(front->right);
		            flag=1;
		            visited[front->right]=1;

		        }
		        
		        if(nodeToParent[front] && !visited.count(nodeToParent[front])){
		            q.push(nodeToParent[front]);
		            flag=1;
		            visited[nodeToParent[front]]=1;

		        }
		    }
		    if(flag){
		        timex++;
		    }
		    
		}
	}
	int minTime(Node* root, int target) {
		// code here
		map<Node*, Node*> nodeToParent; int timex=0;
		Node* ans = createMapping(root, target, nodeToParent);
		solve(ans, nodeToParent, timex);
		return timex;
		
	}
};
