class Solution {
public:
  int drow[4] = {-1,0,1,0};
  int dcol[4] = {0,1,0,-1};
    int getMaximumGold(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      int ans = 0;
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] != 0){
                ans = max(ans,dfs(grid,i,j));
            }
        }
      }
      return ans;
    }
    int dfs(vector<vector<int>>& grid , int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i >= n || j<0 || j >= m || grid[i][j] == 0) return 0;
        int curval = grid[i][j];
        int maxval = 0;
        for(int d = 0; d<4; d++){
            int ni = i + drow[d];
            int nj = j+ dcol[d];
            grid[i][j] = 0;
            maxval = max(maxval,curval+dfs(grid,ni,nj));
            grid[i][j] = curval;
        }
        return maxval;
    }
};
