// recursive soln
int solve(int W,int wt[], int val[], int i,int n)
{
    if(n==0 || W==0) // think of min. valid input
        return 0; 
    if(wt[i] > W)
        return solve(W,wt,val,i-1,n-1);
    int op1 = solve(W , wt , val , i-1 , n-1); // don't include
    int op2 = solve(W-wt[i] , wt , val , i-1 , n-1) + val[i]; // include the bag
    return max(op1,op2);
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
   return solve(W,wt,val,n-1,n);
}
// Make the DP mat only for vars which are changing
// Memoized code
int dp[1005][1005];
int solve(int W,int wt[], int val[], int i,int n)
{
    if(n==0 || W==0) // think of min. valid input
        return 0;
    if(dp[i][W] != -1)
        return dp[i][W];
    if(wt[i] > W)
        return dp[i][W] = solve(W,wt,val,i-1,n-1);
    int op1 = solve(W , wt , val , i-1 , n-1);
    int op2 = solve(W-wt[i] , wt , val , i-1 , n-1)+val[i];
    return dp[i][W] = max(op1,op2);
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    memset(dp,-1,sizeof(dp));
   return solve(W,wt,val,n-1,n);
}
// using tabular DP
int knapSack(int W, int wt[], int val[], int n) 
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
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                }
            }
        }
        return dp[n][W];
    }
