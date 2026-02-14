/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<unordered_map>

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        Node* prev=NULL;
        Node*temp=head;int i=1;
        unordered_map<int,int> ll;
        while(temp!=NULL){
            if(!ll.count(temp->data)){
                ll[temp->data]=i;
                i++;
                prev=temp;
                temp=temp->next;
            }else{
                prev->next=temp->next;
                temp=prev->next;
            }
        }
        return head;
    }
};