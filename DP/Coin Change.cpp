// find no. of ways to make N cents
// there are multiple cases for the same hence, DP
// it's unbounded knapsack
// hence, consider dp[i][j] = ... + dp[i][j-S[i-1]];
long long int count(int S[], int m, int n) {
        long long int dp[m+1][n+1];
        for(int i=0; i<=n; ++i)
            dp[0][i] = 0;
        for(int i=0; i<=m; ++i)
            dp[i][0] = 1;
        for(int i=1; i<=m; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(S[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    int x = (j-S[i-1]);
                    dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]];
                }
                //cout << i << " " << j <<" "<< dp[i][j] << endl;
            }
        }
        return dp[m][n];
    }
