class Solution {
public:

    int numDecodings(string s) {

        // ----------- DYNAMIC PROGRAMMING METHOD -------
//         int n = s.size();
//         vector<int> dp(n+1);

//         dp[n] = 1;
//         if(s[n-1]!='0') dp[n-1] = 1;
//         else dp[n-1] = 0;

//         for(int i=n-2; i>=0; i--){
            
//             if(s[i] == '0'){
//                 dp[i] = 0; continue;
//             }

//             // take single digit
//             int x = dp[i+1];

//             // take 2 digits
//             int y = 0;
//             int d1 = s[i]-'0', d2 = s[i+1]-'0';
//             if( 10*d1+d2 < 27) y = dp[i+2];
            
//             // number of ways to decode till ith position
//             dp[i] = x+y;
//         }

//         return dp[0];
        
        
        //  -------------- DP SPACE OPTIMIZED ---------
        // We can do this as DP[i] is dependent on prev 2 values only - dp[i+1] and dp[i+2]

        int n = s.size();
        if(n == 0) {
            return 1;
        }
        if(n == 1) {
            if(s[0]=='0') return 0;
            return 1;
        }

        // vector<int> dp(n+1);
        int twoPlacesAhead = 1;
        //dp[n] = 1;

        int onePlaceAhead = 0;
        if(s[n-1]!='0') {
            onePlaceAhead = 1;
            //dp[n-1] = 1;
        }
        // else dp[n-1] = 0;

        int currPlace = 0;
        for(int i=n-2; i>=0; i--){
            
            if(s[i] == '0'){
                // dp[i] = 0; 
                currPlace = 0;
                twoPlacesAhead = onePlaceAhead;
                onePlaceAhead = currPlace;
                continue;
            }

            // take single digit
            // int x = dp[i+1];
            int x = onePlaceAhead;

            // take 2 digits
            int y = 0;
            int d1 = s[i]-'0', d2 = s[i+1]-'0';
            if( 10*d1+d2 < 27){ 
                y = twoPlacesAhead;
                // y = dp[i+2];
            }
            
            // number of ways to decode till ith position
            // dp[i] = x+y;
            currPlace = x+y;
            twoPlacesAhead = onePlaceAhead;
            onePlaceAhead = currPlace;

        }

        // return dp[0];
        return currPlace;
    }
};
