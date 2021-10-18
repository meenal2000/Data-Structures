// Unbounded knapsack
int knapSack(int n, int W, int val[], int wt[])
    {
        int dp[n+1][W+1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; ++i)
        {
            for(int j=1;j<=W;++j)
            {
                if(wt[i-1] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j]); // we took dp[i] here as that element can be processed again
                }
            }
        }
        return dp[n][W];
    }
