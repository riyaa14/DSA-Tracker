class Solution {
public:

    int getminPathSum(vector<vector<int>>& grid, int i, int j, int n, int m){

        if(i==n-1 and j==m-1) return grid[i][j];
        if(i==n or j==m) return -1;

        int x = getminPathSum(grid, i+1, j, n, m);
        int y = getminPathSum(grid, i, j+1, n, m);

        if(x==-1) return y+grid[i][j];
        if(y==-1) return x+grid[i][j];

        return min(x, y) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, grid[n-1][m-1]));

        for(int i=n-2; i>=0; i--){
            dp[i][m-1] = dp[i+1][m-1] + grid[i][m-1];
        }

        for(int j=m-2; j>=0; j--){
            dp[n-1][j] = dp[n-1][j+1] + grid[n-1][j];
        }

        // dp[n-1][m-1] = grid[n-1][m-1];

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){

                dp[i][j] = min(dp[i+1][j], dp[i][j+1])+grid[i][j];

            }
        }

        return dp[0][0];
    }
};
