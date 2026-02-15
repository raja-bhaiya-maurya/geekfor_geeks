/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
    Node* top=nullptr;
    

  public:
    myStack() {
        // Initialize your data members
    }
    bool isEmpty() {
        // check if the stack is empty
        if(top==nullptr) return 1;
        else return 0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
       
         Node* newnode= new Node(x);
         newnode->next=top;
        top=newnode;
     
      
    }

    void pop() {
        // Removes the top element of the stack
        if(isEmpty()){
            return;
        }else{
           Node* temp= top;
           top=top->next;
           delete temp;
            
        
    }
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()){
            return -1;
        }else{
            return top->data;
        }
    }

    int size() {
        int size=0;
        // Returns the current size of the stack.
        Node* temp= top;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        return size;
        
    }
};