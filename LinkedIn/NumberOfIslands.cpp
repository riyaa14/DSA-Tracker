class Solution {
  public:
  
    vector<int> x = {0, 0, 1, -1, 1, -1, -1, 1};
    vector<int> y = {1, -1, 0, 0, 1, -1, 1, -1};
  
    void dfs(vector<vector<char>> &grid, int i, int j, int n, int m){
        
        if(i==n or j==m or i==-1 or j==-1 or grid[i][j] == '0' or grid[i][j] == '2') return;
        
        grid[i][j] = '2'; // to mark as visited
        
        // visit all the neighbours 
        for(int xMove : x){
            for(int yMove : y){
                dfs(grid, i+xMove, j+yMove, n, m);
            }
        }
        
        return;
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        int noOfIsland = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m);
                    noOfIsland++;
                }
            }
        }
        
        return noOfIsland;
    }
};
