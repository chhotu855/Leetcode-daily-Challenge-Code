class Solution {
public:
   int drow[4] = {-1,0,1,0};
   int dcol[4] = {0,1,0,-1};
   bool isValid(vector<vector<bool>>& vis , int i , int j){
    int n = vis.size();
    if(i < 0 || i>=n || j < 0 || j >= n || vis[i][j]) return false;
    return true;
   }
    bool isSafe(vector<vector<int>> & distToThief,int safeDist){
        int n = distToThief.size();
        queue<pair<int,int>>q;
        if(distToThief[0][0] < safeDist) return false;
        q.push({0,0});
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        while(!q.empty()){
            int currRow = q.front().first , currCol = q.front().second;
            q.pop();
            if(currRow == n-1 && currCol == n-1) return true;
            for(int d = 0; d<4; d++){
                int newRow = currRow+drow[d];
                int newCol = currCol+dcol[d];
                if(isValid(vis,newRow,newCol)){
                    if(distToThief[newRow][newCol] < safeDist) continue;
                    vis[newRow][newCol] = true;
                    q.push({newRow,newCol});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<bool>>vis(n,vector<bool>(n,false));
      vector<vector<int>>distToThief(n,vector<int>(n,-1));
      queue<pair<int,int>>q;
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                vis[i][j] = true;
                q.push({i,j});
            }
        }
      }
      int len = 0;
      while(!q.empty()){
        int size = q.size();
        while(size--){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            distToThief[currRow][currCol] = len;
            for(int d = 0; d<4;d++){
                int newRow = currRow+drow[d];
                int newCol = currCol+dcol[d];
                if(!isValid(vis,newRow,newCol)) continue;
                vis[newRow][newCol] = true;
                q.push({newRow,newCol});
            }
        }
        len++;
      }
      int left = 0, right = len;
      int ans = 0;
      while(left <= right){
        int mid = left + (right-left)/2;
        if(isSafe(distToThief , mid)){
            ans = mid;
            left = mid+1;
        }
        else right = mid-1;
      }
      return ans;
    }
};
