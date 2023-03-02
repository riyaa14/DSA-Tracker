// ***************** Branch and Bound Algorithm *********************

class Solution {
public:
    
    void solve(vector<vector<string>>& ans, vector<string>& config, int row, int col, int n, set<int>& posCol, set<int>& posDia1, set<int>& posDia2){
       
        // base case
        if(row >= n){
            ans.push_back(config);
            return;
        }

        // recursive case
        for(int i = 0; i<n; i++){
            col = i;

            bool isValidPos = true;
            if(posCol.find(col) != posCol.end() or posDia1.find(col+row) != posDia1.end() or posDia2.find(row-col+n) != posDia2.end()) isValidPos = false;

            if(isValidPos){
                config[row][col] = 'Q';
                posDia1.insert(row+col);
                posDia2.insert(row-col+n);
                posCol.insert(col);
                solve(ans, config, row+1, 0, n, posCol, posDia1, posDia2);
                config[row][col] = '.';
                posDia1.erase(row+col);
                posDia2.erase(row-col+n);
                posCol.erase(col);
            }
        }
        
    }

    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<string> config(n, string(n, '.'));
        set<int> posDia1, posDia2, posCol;
        solve(ans, config, 0, 0, n, posCol, posDia1, posDia2);
        return ans;
    }

};
