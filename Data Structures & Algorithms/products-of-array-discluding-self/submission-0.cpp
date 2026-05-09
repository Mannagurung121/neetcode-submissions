class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int pref=1;
            vector<int>ans(nums.size(),1);
            for(int i=1; i<nums.size(); i++ ){
                    pref *=nums[i-1];
                ans[i]=pref;
            }
            int suff=1;
            for(int i=nums.size()-2; i>=0; i-- ){

                    suff*=nums[i+1];
                    ans[i]= suff*ans[i];
                
            }
            return ans;
    }
};
