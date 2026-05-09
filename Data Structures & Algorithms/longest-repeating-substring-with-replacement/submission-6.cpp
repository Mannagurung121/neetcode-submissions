class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxi=0;
        int len=0;
        vector<int>mpp(26,0);
        while(r<s.size()){
            mpp[s[r]-'A']++;
            maxi=max(maxi,mpp[s[r]-'A']);
           
            while((r-l+1)-maxi>k){
                mpp[s[l]-'A']--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};
