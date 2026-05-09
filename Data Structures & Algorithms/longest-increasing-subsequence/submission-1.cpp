class Solution {
public:
    int solve( vector<int>& arr,int prev, int curr,  vector<vector<int>>&dp){

        if(curr==arr.size()){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }

        int take=0;
        if(prev==-1 || arr[curr]>arr[prev]){

            take=1+solve(arr,curr,curr+1,dp);
        }
        int not_take=0;

        not_take=0+solve(arr,prev,curr+1,dp);
    return dp[curr][prev+1]= max(take,not_take);

    }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return solve(nums,-1,0,dp);
    }
};
