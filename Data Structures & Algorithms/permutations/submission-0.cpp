class Solution {
public:
void solve(vector<int>& nums,int index, int n, vector<vector<int>>&ans){
    if(index==n){
        ans.push_back(nums);
    }

    for(int i=index; i<nums.size(); i++){
        swap(nums[i],nums[index]);
        solve(nums,index+1,n,ans);
        swap(nums[i],nums[index]);
    }



}

    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
            // vector<int>temp;

         solve(nums, 0, nums.size()-1,ans);
        return ans;
    }
};
