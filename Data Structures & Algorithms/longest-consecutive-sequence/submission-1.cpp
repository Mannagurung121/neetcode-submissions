class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxi=1;
        for(int i=0; i<nums.size(); i++){
            int count =1;
            int elm= nums[i]+1;
            for(int j=i; j<nums.size(); j++){
                if(elm==nums[j]){
                    count++;
                    maxi=max(count,maxi);
                    elm+=1;
                }
            }
        }
        return maxi;
    }
};
