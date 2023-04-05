class Solution {
public:

    int edit(string& word1, string& word2, int i, int j, int n, int m, vector<vector<int>> &dp){

        // base cases
        if(i >= word1.size()) {
            return dp[i][j] = m-j;
            // return m-j;
        }

        if(j >= word2.size()) return dp[i][j] = n-i; // erase all the leftover chars in word1

        // recursive cases
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) {
            int x = edit(word1, word2, i+1, j+1, n, m, dp);
            return dp[i][j] = x;
        }

        // 1. delete
        int x = INT_MAX;
        x = edit(word1, word2, i+1, j, n, m, dp);
        
        // 2. replace
        int y = edit(word1, word2, i+1, j+1, n, m, dp);

        // 3. insert
        
        int z = edit(word1, word2, i, j+1, n, m, dp); // we have to perform edit on inserted element as well. It might be deleted, replaced or we might insert something more.

        return dp[i][j] = min(x, min(y, z)) + 1;

    }

    int minDistance(string word1, string word2) {
        
        if(word1 == word2) return 0;
        int n = word1.size(), m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return edit(word1, word2, 0, 0, n, m, dp);
    }
};
