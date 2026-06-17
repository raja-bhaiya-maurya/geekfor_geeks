/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	void createInorderMapping(unordered_map<int, int> &inorderM, vector<int> &v) {
		for (int i = 0; i<v.size(); i++) {
			inorderM[v[i]] = i;
		}
	}
	
	Node* createBT(int ins, int ine, unordered_map<int, int> &inorderM, vector<int> &inorder, vector<int> &preorder, int& preidx, int n) {
		
		if (preidx >= n || ins>ine) {
			return NULL;
		}
		int ele = preorder[preidx++];
		Node* root = new Node(ele);
		int pos = inorderM[ele];
		
		root->left = createBT(ins, pos - 1, inorderM, inorder, preorder, preidx, n);
		root->right = createBT(pos + 1, ine, inorderM, inorder, preorder, preidx, n);
		
		return root;
		
	}
	
	Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
		// code here
		unordered_map <int, int>inorderM;
		createInorderMapping(inorderM, inorder);
		
		int ins = 0;
		int ine = inorder.size() - 1;
		int preidx = 0;
		
		Node* ans = createBT(ins, ine, inorderM, inorder, preorder, preidx, preorder.size());
		return ans;
		
	}
};
