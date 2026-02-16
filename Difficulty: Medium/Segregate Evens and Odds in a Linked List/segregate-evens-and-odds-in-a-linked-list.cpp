// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* newnode= new Node(-1);
        Node* temp=head;
        Node* prev=NULL;
        Node* restemp=newnode;
        Node* reshead=newnode;
        
        while(temp!=NULL){
            if((temp->data)%2!=0){
                prev=temp;
                temp=temp->next;
            }
            else{
                if(prev==NULL){
                    head= head->next;
                    temp->next=NULL;
                    // temp=head;
                    restemp->next=temp;
                    restemp=restemp->next;
                    temp=head;
                }
                else{
                prev->next=temp->next;
                // prev=prev->next;
                // temp=temp->next;
                restemp->next=temp;
                temp->next=NULL;
                restemp=restemp->next;
                temp=prev->next;
                    
                }
            }
            
           
        }
        restemp->next=head;

         return reshead->next;
        
    }
};