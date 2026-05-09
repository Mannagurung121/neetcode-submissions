class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int startrow=0;
        int startcol=0;
        int endcol=matrix[0].size()-1;
        int endrow=matrix.size()-1;
        int m=matrix[0].size();
        int n=matrix.size();
        
        while(ans.size()<m*n){

            for(int i=startcol; i<=endcol; i++){
                ans.push_back(matrix[startrow][i]);
            }
            startrow++;
             for(int i=startrow; i<=endrow; i++){
                ans.push_back(matrix[i][endcol]);
            }
            endcol--;
            if(startrow<=endrow){
                for(int i=endcol; i>=startcol; i--){
                ans.push_back(matrix[endrow][i]);
            }
            }
            endrow--;
            if(startcol<=endcol){
                for(int i=endrow; i>=startrow; i--){
                ans.push_back(matrix[i][startcol]);
            }
            }
            startcol++;
        }
        return ans;
    }
};
