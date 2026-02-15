class myStack {
  public:
    int top=-1;
  int arr[1000];
  int size;
        
       
    myStack(int n) {
        // Define Data Structures
        size=n;
    }


    bool isEmpty() {
        // check if the stack is empty
        if(top==-1)return true; else return false;
    }

    bool isFull() {
        // check if the stack is full
        if(top==size-1)return true; else return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()){
            return ;
            
        }else{
           top++;
        arr[top]=x; 
        }
        
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()){
            return ;
        }else{
            arr[top]=-1;
            top--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty())return -1;
        else
        return arr[top];
    }
};