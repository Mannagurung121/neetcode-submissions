class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax=0;
        int Maxi=INT_MIN;
        for(int i=0; i<nums.size() ;i++){

            currentMax=max(currentMax+nums[i],nums[i]);
            Maxi=max(Maxi,currentMax);
        }


return Maxi;
    }
};
