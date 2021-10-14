// subset sum 
bool isSubsetSum(int n, int arr[], int sum){
        bool dp[n+1][sum+1];
        for(int i=0; i<n+1; ++i)
        {
            for(int j=0; j<sum+1; ++j)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j]=0;
                else
                {
                    if(arr[i-1] > j) // current value is greater than sum , hence, we see if the same sum occurs before for any subproblem
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]); 
                }
            }
        }
        return dp[n][sum];
    }
