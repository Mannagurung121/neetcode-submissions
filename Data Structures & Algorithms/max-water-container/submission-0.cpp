class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int mini=INT_MAX;
        int ans=INT_MIN;

        while(i<j){
            int wt=j-i;

            mini=min(heights[i],heights[j]);
            ans=max(ans,wt*mini);
            if(heights[i]<heights[j]){
                    i++;
            }
            else{
                j--;
            }




        }
        return ans;
    }
};
