class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code hereint
        int j=0;
    stack< int > s;
       int size=s.size();
        while(!st.empty()){
           s.push(st.top());
            st.pop();
        }
        st.swap(s);
        // for(int i=0;i<size;i++){
        //     st.push(s[i]);
        // }
    }
};