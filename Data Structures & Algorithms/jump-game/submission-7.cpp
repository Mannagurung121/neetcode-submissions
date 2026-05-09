class Solution {
public:
    bool canJump(vector<int>& nums) {
         int i=0;
         int maxJump=0;
        while(i<=maxJump){
            maxJump=max(maxJump,i+nums[i]);

            if(maxJump>=nums.size()-1){
                    return true;
            }
            i++;
            
            
        }
        
        return false;
    }
};
