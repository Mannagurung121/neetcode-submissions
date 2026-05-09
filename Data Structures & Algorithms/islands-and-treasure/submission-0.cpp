class Solution {
public:
    bool check(vector<vector<int>>& grid,int row,int col,int n, int m){
        return row>=0 &&row<n && col>=0 &&col<m &&grid[row][col]==2147483647;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        bool isZero=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    isZero=true;
                }
            }
        }
        if(isZero==false){
            return;
        }
        int delRow[4]={0,0,-1,1};
        int delCol[4]={1,-1,0,0};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.second.first;
            int c=it.second.second;
            int step=it.first;
            for(int i=0; i<4; i++){
                int row=delRow[i]+r;
                int col =delCol[i]+c;
                if(check(grid, row,col,n,m)){
                    grid[row][col]=step+1;
                    q.push({step+1,{row,col}});
                }
            }
        }
        return;

    }
};
