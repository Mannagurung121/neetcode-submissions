class Solution {
public:
     bool helper(string cut){
      
      
      int i=0; 
      int j=cut.size()-1;
      while(i<j){
          if(cut[i]!=cut[j]){
              return false;
          }
          i++;
          j--;
      }
      return true;
  }
   void solve(string s, vector<string> temp, vector<vector<string>> &ans){
            if(s.size()==0){
                ans.push_back(temp);
                return;
        }
  
    for(int i=0; i<s.size(); i++){
        string cut=s.substr(0,i+1) ;
        if(helper(cut)){
            temp.push_back(cut);
            solve(s.substr(i+1),temp,ans);
            temp.pop_back();
        }
    }
   }

    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;    
      vector<string>temp;
        int count=0;
        solve(s,temp,ans);
        return ans;
    }
};
