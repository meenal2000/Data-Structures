// we will return false if sum is odd
// if sum is even then, we just need to check if sum/2 is present as a subset in our array
bool solve(int arr[],int N, int sum)
    {
        int dp[N+1][sum+1];
        for(int i=0; i<=sum; ++i)
            dp[0][i] = 0;
        for(int j=0; j<=N; ++j)
            dp[j][0] = 1;
        for(int i=1; i<=N; ++i)
        {
            for(int j=1; j<=sum; ++j)
            {
                if(arr[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; ++i)
            sum += arr[i];
        if(sum%2 != 0)
            return 0;
        return solve(arr, N, sum/2);
    }
