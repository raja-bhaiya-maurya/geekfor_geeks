class Solution {
    
  
  public:
  //precedence
  int prec(char ch){
      if(ch=='^'){
          return 3;
      }else if(ch=='*'||ch=='/'){
          return 2;
      }else if(ch=='+'||ch=='-'){
          return 1;
      }else{
          return -1;
      }
  }
  //right associate
  bool isRightAssociate(char ch){
      if(ch=='^')
      return true;
      else return false;
  } 
  
    string infixToPostfix(string& s) {
        // code here
        char ch;
        string res="";
        stack<char> st;
        //operands
        for(int i=0;i<s.length();i++){
            ch=s[i];
            if(ch>='a' && ch<='z'||
               ch>='A' && ch<='Z'||
               ch>='0' && ch<='9'){
                
                res+=ch;
            }
            //open bracets
            else if(ch=='('){
                st.push(ch);
            }
            //close brackets
            else if(ch==')'){
                while(!st.empty()&& st.top()!='('){
                    res+=st.top();
                    st.pop();
    
                }
                st.pop();
                
            }
            
            //operators
            else{while(!st.empty()&& st.top()!='('&&
                        (prec(ch)<prec(st.top())||
                        (prec(ch)==prec(st.top())&& !isRightAssociate(ch)))){
                            res+=st.top();
                            st.pop();
                    }
                    st.push(ch);
                
            }
            
        }
        
        //pop remaining operators in stack
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
         
         return res;
          
        
        
    }
};
