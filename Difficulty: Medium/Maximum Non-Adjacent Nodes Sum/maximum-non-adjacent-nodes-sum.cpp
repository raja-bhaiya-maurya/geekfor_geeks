/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	pair<int,int> solve(Node* root) {
		if (root == NULL) {
			pair<int, int>p = make_pair(0, 0);
			return p;
		}
		
		pair<int, int> left = solve(root->left);
		pair<int, int> right = solve(root->right);
		
		pair<int, int> res;
		/* 
		including  curr node: 
		if include curr-> you have to exclude its child
		*/
		res.first = root->data + left.second + right.second;
		
		/*
		excluding curr node:  
		if you exclude curr-> 
		you can include maxm of the child or the grand child
		*/
		res.second = max(left.first, left.second) 
		            + max(right.first, right.second);
		
		return res;
		
	}
	int getMaxSum(Node *root) {
		// code here
		if (root == NULL)
			return 0;
		pair<int, int>ans = solve(root);
		//pair<include,exclude>ans;
		return max(ans.first, ans.second);
		
	}
};
