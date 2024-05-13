class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
     int m = grid[0].size();
     int n = grid.size();
     for(int row = 0; row<n; row++){
        if(grid[row][0] == 0) flipRows(grid,row);
     }
     int score = n*pow(2,m-1);
     for(int col = 1; col<m; col++){
        int count1 = countOnes(grid,col);
        int count0 = n-count1;
        score += max(count1,count0) * pow(2,m-1-col);
     }
     return score;
    }
    void flipRows(vector<vector<int>>& grid , int row){
        int m = grid[0].size();
        for(int col=0; col<m; col++){
            grid[row][col] = (grid[row][col] == 1) ? 0 : 1;
        }
    }
    int countOnes(vector<vector<int>>&grid, int col){
        int n = grid.size();
        int cnt = 0;
        for(int row=0; row<n; row++){
            if(grid[row][col] == 1) cnt++;
        }
        return cnt;
    }
};
