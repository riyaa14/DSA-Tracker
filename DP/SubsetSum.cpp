bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        int dp[n+1][sum+1];
        
        for(int s=0; s<sum+1; s++){
            dp[n][s] = false;
        }
        
        for(int i=0; i<n+1; i++){
            dp[i][sum] = true;
        }
        
        // for(int i=0; i<n+1; i++){
        //     for(int j=0; j<sum+1; j++){
        //         if(i==n) dp[i][j] = false;
        //         if(j==sum) dp[i][j]=true;
        //     }
        // }
        
        for(int i=n-1; i>=0; i--){
            for(int j=sum; j>=0; j--){
                if(j+arr[i] > sum ) dp[i][j] = dp[i+1][j];
                else dp[i][j] = dp[i+1][j] or dp[i+1][j+arr[i]];
            }
        }
        
        return dp[0][0];
    }
