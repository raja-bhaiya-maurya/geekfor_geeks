class Solution {
  private:
        bool isSafe(vector<vector<int>>& maze,vector<vector<int>>& visited,int x,int y,int n){
            if((x>=0 && x<n) &&( y>=0 && y<n) && (visited[x][y]==0 )&& (maze[x][y]==1) )
                return true;
                else
                return false;
        }
       
        void solve(vector<vector<int>>& maze,vector<vector<int>>& visited,vector <string> &ans,int n,int x,int y,string path){
        
      
            if((x==n-1) && (y==n-1)){
                ans.push_back(path);
                return;
            }
            
            //visited 
            visited[x][y]=1;
            
            //left
           int newx= x;
           int newy= y-1;
            if(isSafe(maze,visited,newx,newy,n)){
               path.push_back('L');
                solve(maze,visited,ans,n,newx,newy,path);
                path.pop_back(); 
            }
            
            
            //right
             newx= x;
             newy= y+1;
               if(isSafe(maze,visited,newx,newy,n)){
                path.push_back('R');
                solve(maze,visited,ans,n,newx,newy,path);
                path.pop_back();
            }
            
            //up
             newx= x-1;
             newy= y;
              if(isSafe(maze,visited,newx,newy,n)){
                path.push_back('U');
                solve(maze,visited,ans,n,newx,newy,path);
                path.pop_back();
            }
            
            
            //down
             newx= x+1;
             newy= y;
              if(isSafe(maze,visited,newx,newy,n)){
                path.push_back('D');
                solve(maze,visited,ans,n,newx,newy,path);
                path.pop_back();
            }
            
            
            visited[x][y]=0;
        }
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
         string path="";
        
        int n= maze.size();
        vector <string> ans;
        if(maze[0][0]==0) return ans;
        vector<vector<int>> visited=maze;
        //initialize by 0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        int srcx=0;
        int srcy=0;
         
        solve(maze,visited,ans,n,srcx,srcy,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};