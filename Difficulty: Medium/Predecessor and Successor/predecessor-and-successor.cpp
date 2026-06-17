/* BST Node
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
};
*/

class Solution {
	public:
	void solve1(Node* root, vector<Node*> &inorder) {
		if (root == NULL) {
			return ;
		}
		
		solve1(root->left, inorder);
		
		inorder.push_back(root);
		
		solve1(root->right, inorder);
		
	}
	vector<Node*> find(vector<Node*> &inorder, int &key) {
		
		vector<Node*> ans(2, NULL);
		
		int n = inorder.size();
		
		// Case 1: Key exists
		for (int i = 0; i < n; i++) {
			
			if (inorder[i]->data == key) {
				
				if (i > 0)
					ans[0] = inorder[i - 1];
				
				if (i < n - 1)
					ans[1] = inorder[i + 1];
				
				return ans;
			}
		}
		
		// Case 2: Key does not exist
		int idx = 0;
		
		while (idx < n && inorder[idx]->data < key)
			idx++;
		
		// predecessor
		if (idx > 0)
			ans[0] = inorder[idx - 1];
		
		// successor
		if (idx < n)
			ans[1] = inorder[idx];
		
		return ans;
	}
	vector<Node*> findPreSuc(Node* root, int key) {
		// code here
		vector<Node*> inorder;
		solve1(root, inorder);
		vector<Node*> ans = find(inorder, key);
		return ans;
	}
};
