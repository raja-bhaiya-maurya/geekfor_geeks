class Solution {
  private:
    bool isPossibleSoln(vector<int> arr,int size, int k,int mid){
        int studentCount=1;
        int pageSum=0;
        for(int i=0;i<size;i++){
            if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
            }else{
                studentCount++;
                if(studentCount<=k && arr[i]<=mid){
                    pageSum= arr[i];
                }else{
                    return false;
                }
            }
        }
        return true;
    }  
    
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int size= arr.size();
        if(size<k) return -1;
        int s=0;
        int e=0;
        for(int i=0;i<size;i++){
            e += arr[i];
        }
        int mid= s+(e-s)/2;
        int ans=-1;
        
        while(s<=e){
            if(isPossibleSoln(arr,size,k,mid)){
                ans= mid;
                e=mid-1;// aiming to minimize the pages allocation
            }else{
                s=mid+1;
            }
           mid= s+(e-s)/2;
        }
        return ans;
    }
};