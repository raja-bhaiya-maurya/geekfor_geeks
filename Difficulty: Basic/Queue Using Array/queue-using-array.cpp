class myQueue {

  public:
  int front=-1;
  int rear=-1;
  int size;
  int arr[1000];
  
    myQueue(int n) {
        size=n;
        // Define Data Structures
    }
   

    bool isEmpty() {
        // check if the queue is empty
        if(front==-1 && rear ==-1) return true;
        else return false;
    }

    bool isFull() {
        // check if the queue is full
        if(front ==0&&rear==(size-1)) return true; 
        else return false;
        
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()){
            return ;
        }
        if(rear==-1)
        rear=front=0;
        else{
            rear++;
            
        }
        arr[rear]=(x);
        
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return;
        }
        // arr[front]=-1;
        if(rear==front){
            front=rear=-1;
        }
      else{
        front++;
        }
       
        
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
        
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
        
    }
};