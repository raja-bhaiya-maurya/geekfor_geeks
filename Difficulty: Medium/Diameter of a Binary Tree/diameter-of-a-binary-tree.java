/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = right = null;
    }
} */

class Solution {
    int dia=0;
    public int diameter(Node root) {
        // code here
        if(root==null) return 0;
        diaa(root);
        
        return dia;
        
    }
    public int diaa(Node root){
        if(root==null) return 0;
        int l=diaa(root.left);
        int r=diaa(root.right);
        
      
        dia=Math.max(l+r,dia);
        return Math.max(l,r)+1;
    }
}