class Solution {
public:
    void solve(vector<int>& nums, int target,int index,vector<int>&sum,vector<vector<int>>&ans ){
        if(index>=nums.size()){
            if(target==0){
                ans.push_back(sum);
            }
            return;
        }


        if(nums[index]<=target){
            sum.push_back(nums[index]);
            solve(nums,target-nums[index],index,sum,ans);
            sum.pop_back();
        }

        solve(nums,target,index+1,sum,ans);
    }




    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>sum;
        vector<vector<int>>ans;


        solve(nums,target,0,sum,ans);
        return ans;
    }
};
