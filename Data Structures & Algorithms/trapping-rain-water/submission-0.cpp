class Solution {
public:
    int trap(vector<int>& arr) {
        
        int l=0;
        int r=arr.size()-1;

        int lmax=0;
        int rmax=0;
        int ans=0;
    while(l<r){

         lmax=max(arr[l],lmax);
         rmax=max(arr[r],rmax);
        if(lmax<rmax){
            ans+=(lmax-arr[l]);
            l++;
        }
        else{
            ans+=(rmax-arr[r]);
            r--;
        }
    }
return ans;
    }
};
