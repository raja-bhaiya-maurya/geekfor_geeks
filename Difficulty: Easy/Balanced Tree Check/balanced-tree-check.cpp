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
	private:
	 int height(Node* root){
     if (root==NULL) return 0;
      
     int lefth =height(root->left);
     int righth= height(root->right);
     
      int ans= max(lefth , righth)+1 ;
      return ans;
}
	public:
	int isBalanced(Node* root) {
		if (root == NULL) {
			return true;
		}
		
		bool left = isBalanced(root->left);
		bool right = isBalanced(root->right);
		
		bool diff = abs(height(root->left) - height(root->right)) <= 1;
		
		if(left && right && diff){
		    return true;
		}else
		return false;
	}
	
};
