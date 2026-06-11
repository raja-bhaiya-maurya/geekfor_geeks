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
	void leftView2(Node* root, map<int, int>& m, int lvl) {
		
		if (root == NULL)
			return;
		if (!m.count(lvl)) { m[lvl] = root->data; }
		if (root->left) {
			leftView2(root->left, m, lvl + 1);
		}
		if (root->right) {
			leftView2(root->right, m, lvl + 1);
		}
	}
	vector<int> leftView(Node *root) {
		// code here
		vector<int> ans;
		map<int, int> m; // <lvl,data>
		leftView2(root, m, 0);
		
		for (auto i:m) {
			ans.push_back(i.second);
		}
		
		return ans;
		
	}
};
