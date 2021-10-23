// MCM memoized code
// we are just partitioning at different points and then, taking the ans that's min
// dp matrix to store that we already computed an answer for the given row no. and col no.
int dp[101][101];
    int solve(int arr[] , int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for(int k=i; k<=j-1; ++k)
        {
            int tmpAns = solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
            if(tmpAns < mn)
                mn = tmpAns;
        }
        return dp[i][j] = mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
