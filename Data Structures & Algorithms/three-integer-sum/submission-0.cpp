class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
         // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==arr[i-1] && i>0){
                continue;
            }
            int j=i+1;
            int k=arr.size()-1;
            
            while(j<k){
                
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    
                    ans.push_back({arr[i],arr[j],arr[k]});
                    k--;
                    j++;
                    while(j<k && arr[j]==arr[j-1]){
                        j++;
                    }
                     while(j<k && arr[j]==arr[j-1]){
                        j++;
                     }
                     while(j<k && arr[k]==arr[k+1]){
                        k--;
                    }
                    
                }
            
                
            }
        }
        return ans;
    }
};
