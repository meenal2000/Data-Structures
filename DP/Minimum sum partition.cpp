// here basically we have two find the min. of absolute diff of two subsets
// hence, min|s1-s2|
// s2 = sum-s1
// min|s1-s2| = min|2*s1-sum|
// hence we just need to find the possible sum of a subset == s1
// which will lie somewhere in 1 to (sum/2)
int solve(int arr[],int N, int sum)
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
        int ans = INT_MAX;
        for(int i=0; i<=(sum/2); ++i)
        {
            if(dp[N][i])
            {
                ans = min(ans , sum-(2*i));
            }
        }
        return ans;
    }
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; ++i)
	        sum += arr[i];
	    return solve(arr,n,sum);
	} 
