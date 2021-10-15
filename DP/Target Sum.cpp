int solve(vector<int>&A ,int sum)
    {
        int n = A.size();
        int dp[n+1][sum+1];
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=sum; ++j)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else
                {
                    if(A[i-1] > j)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j]+dp[i-1][j-A[i-1]];
                }
            }
        }
        //cout << sum << "\n";
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        int sum = 0;
        int n = A.size();
        for(int i=0; i<n; ++i)
            sum += A[i];
        int x = (target+sum);
        // x should always be even for to be able to find out
        // x/2 sum in the array . Right??????/
        if(x&1)
            return 0;
        int tmp = solve(A,x/2);
        
        return tmp;
    }
