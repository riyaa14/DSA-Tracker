class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int S = 0;
        for(int i=0; i<N; i++){
            S+=arr[i];
        }
        
        if(S%2!=0) return false;
        
        vector<vector<bool>> dp(N+1, vector<bool>(S, false));
        
      // base case
        for(int i=0; i<=N; i++){
            dp[i][S/2] = true;
        }
      
      // recursive case
        for(int i=N-1; i>=0; i--){
            for(int j=(S/2) - 1; j>=0; j--){
               dp[i][j] = dp[i+1][j+arr[i]] or dp[i+1][j] ;
            }
        }
        
        return dp[0][0];
        
    }
};
