class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        int i=0;
        int d=1;
        ans.push_back(0);
        while(d<=n){
            int i=d;
            int count=0;
            while(i!=0){

                if((i&1)==1){
                    count++;
                }
               i=i>>1;

            }
            ans.push_back(count);
            d++;
        }
        return ans;
    }
};
