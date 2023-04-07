class Solution {
public:

// ------------------ RECURSIVE APPROACH (DFS) - O(8^(N^2)) -> TLE -------------------------------

    // vector<int> dir = {1, 0, -1, 0, 1, 1, -1, -1, 1};

    // int lengthOfShortestPath(vector<vector<int>>& grid, int i, int j, int n){

    //     if(i==n-1 and j==n-1) return 1;

    //     if(i==n or j==n or i==-1 or j==-1 or grid[i][j] == 1) return -1;

    //     grid[i][j] = 1;
    //     int minSteps = INT_MAX;
    //     for(int step = 0; step<dir.size()-1; step++){
    //         if(lengthOfShortestPath(grid, i+dir[step], j+dir[step+1], n) == -1) continue;
    //         minSteps = min(lengthOfShortestPath(grid, i+dir[step], j+dir[step+1], n), minSteps);
    //     }
    //     grid[i][j] = 0;

    //     return minSteps == INT_MAX? -1 : minSteps+1;
    // }

    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     if(grid[n-1][n-1] == 1 or grid[0][0] == 1) return -1;
    //     return lengthOfShortestPath(grid, 0, 0, n);
    // }


    // -------------- DP -> WONT'T WORK, WRONG OUTPUT ------------------------
    // reason? 
    // traversing the graph using DFS doesn't guarantee that we choose the shortest path first. 
    // We might actually choose a long one first, and then based on that path we'll end up calculating and memoizing an incorrect result.

    // ------------------- BFS -> O(N^2)

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if(grid[n-1][n-1] == 1 or grid[0][0] == 1) return -1;
        if(n==1) return 1;
        
        vector<int> dir = {1, 0, -1, 0, 1, 1, -1, -1, 1};

        int lenOfPath = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        q.push({-1, -1});
        //lenOfPath++;

        while(!q.empty()){
            pair<int, int> currPos = q.front();
            q.pop();
            if (currPos.first == -1 && currPos.second == -1) {
                // if this is the last delimiter then no next level thus lenOfPath is not incremented
                if (q.empty()) {
                    break; // no path found
                }

                // if it is not the last delimiter then we'll move to next lvl thus lenOfPath increases
                lenOfPath++;
                q.push({-1, -1}); // delimiter for the next level
                continue;
            }

            if(currPos.first==n-1 and currPos.second==n-1) return lenOfPath;

            for(int k=0; k<dir.size()-1; k++){
                int i = currPos.first + dir[k], j = currPos.second + dir[k+1];
                if(i<n and j<n and i>-1 and j>-1 and grid[i][j] == 0) {
                    q.push({i, j});
                    grid[i][j] = 1;
                }
            }
        }

        return -1;
    }

};
