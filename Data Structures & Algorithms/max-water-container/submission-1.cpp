class Solution {
public:
    int maxArea(vector<int>& arr) {
        int SmallBar=INT_MAX;
        int ans=INT_MIN;
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int len=j-i;
            SmallBar=min(arr[i],arr[j]);
            ans=max(ans,len*SmallBar);
            if(arr[i]<arr[j]){
                i++;
            }
            else{
                j--;
            }



        }
        return ans;
    }
};
