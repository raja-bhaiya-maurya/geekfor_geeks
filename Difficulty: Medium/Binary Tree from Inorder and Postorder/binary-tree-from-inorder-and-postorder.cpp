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
	
	Node* createBT(int ins, int ine, unordered_map<int, int> &inorderM, vector<int> &inorder, vector<int> &postorder, int& posidx) {
		
		if (posidx<0 || ins>ine) {
			return NULL;
		}
		int ele = postorder[posidx--];
		Node* root = new Node(ele);
		int pos = inorderM[ele];
		root->right = createBT(pos + 1, ine, inorderM, inorder, postorder, posidx);
		root->left = createBT(ins, pos - 1, inorderM, inorder, postorder, posidx);
		
		return root;
		
	}
	
	Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// code here
		unordered_map <int, int>inorderM;
		createInorderMapping(inorderM, inorder);
		
		int ins = 0;
		int ine = inorder.size() - 1;
		int posidx = postorder.size() - 1;
		
		Node* ans = createBT(ins, ine, inorderM, inorder, postorder, posidx);
		return ans;
		
	}
};
