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
void left(Node*root, vector<int> &ans) {
    if((root==NULL)|| (root->left==NULL && root->right==NULL)){
        return ;
    }
    ans.push_back(root->data);
    if(root->left){
        left(root->left,ans);
    }else{
        left(root->right,ans);
    }

}
void right (Node*root, vector<int> &ans) {
     if((root==NULL)|| (root->left==NULL && root->right==NULL)){
        return ;
    }
    
    if(root->right){
        right(root->right,ans);
    }else{
        right(root->left,ans);
    }

    ans.push_back(root->data);
}
void leaf (Node*root, vector<int> &ans) {
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    
    leaf(root->left,ans);
    leaf(root->right,ans);

}
class Solution {
	public:
	vector<int> boundaryTraversal(Node *root) {
		// code here
		vector<int> ans;
		
		ans.push_back(root->data);
		
		//left traverse
		left(root->left,ans);
		
		//leaf traverse
		//left subtree
		leaf(root->left,ans);
		
		//right subtree
		leaf(root->right,ans);
		
		//right traverse
		right(root->right,ans);
		

        	
		return ans;
	}
};
