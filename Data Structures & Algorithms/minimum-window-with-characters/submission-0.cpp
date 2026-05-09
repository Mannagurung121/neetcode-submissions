class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;

        for(auto it: t){
            mpp[it]++;
        }

        int left=0;
        int right=0;
        int Index=-1;
        int cnt=0;
        int Minimum=INT_MAX;
        while(right<s.size()){
            if( mpp[s[right]]>0){
                cnt++;
            }
              mpp[s[right]]--;
            while(cnt==t.size()){
                if(Minimum>right-left+1){
                        Minimum=right-left+1;
                        Index=left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]]>0){
                    cnt--;
                }
                left++;

            }
            right++;

        }
        if(Index==-1){
            return "";
        }
        else{
           return s.substr(Index,Minimum);
        }



    }
};
