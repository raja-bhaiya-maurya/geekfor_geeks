class Solution {
  private:
    bool ispossible(vector<int> &stalls, int k, int mid){
        int cowCount=1;
        int lastPos= stalls[0];
        for( int i=0;i<stalls.size();i++){
            if(stalls[i]-lastPos>= mid){
                cowCount ++;
                if(cowCount==k){
                    return true;
                }
                lastPos=stalls[i];
            }
        }
        return false;
        
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int size= stalls.size();
        int s=0;
        int e=stalls[size-1];
        // for(int i=0;i<size;i++){
        //     e=stall[i]>e?stalls[i]:continue;
        // }
        int ans=-1;
        int mid= s+(e-s)/2;
         while(e>=s){
            if(ispossible(stalls,k,mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid= s+(e-s)/2;
            
            
         }
         return ans;
    }
};