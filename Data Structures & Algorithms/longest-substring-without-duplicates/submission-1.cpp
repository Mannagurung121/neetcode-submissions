class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int maxLen;
      if(s.size()==0){
        return 0;
      }
    vector<int>mpp(256,-1);
      int left=0;
      int right=0;
      while(right<s.size()) {
        if(mpp[s[right]]!=-1){
            if(mpp[s[right]]>=left){
                left=mpp[s[right]]+1;
            }
        }
        
        maxLen=max(maxLen,right-left+1);
        mpp[s[right]]=right;
        right++;
      }

return maxLen;

    }
};
