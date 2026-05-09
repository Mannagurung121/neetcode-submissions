class Solution {
public:

    string encode(vector<string>& strs) {
       string st="";
       for(int i=0; i<strs.size(); i++){
            st+=to_string(strs[i].size())+ "#"+strs[i];
       }
       return st;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        int j=0;
        while(j<s.size()){
                
            while(s[j]!='#'){
                j++;
            }
            int len= stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            j=j+len+1;
            i=j;
        }
        return ans;
    }
};
