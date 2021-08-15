// time - O(n*n)
// space - O(n*n)
long long int mod = 1e9+7;
    long long int solve(string &s , long long int i, long long int j,vector< vector<long long int> > &dp)
    {
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i == j)
            return dp[i][j] = 1;
        if(s[i] == s[j])
            return dp[i][j] = (1 + mod + solve(s,i+1,j,dp)%mod + solve(s,i,j-1,dp)%mod) %mod;
        else
            return dp[i][j] = (solve(s,i+1,j,dp)%mod + solve(s,i,j-1,dp)%mod - solve(s,i+1,j-1,dp)%mod +mod ) %mod;
    }
    long long int countPS(string str)
    {
       long long int n = str.size() ;
       vector< vector<long long int> > dp(n, vector<long long int>(n,-1));
       return solve(str,0,n-1,dp) % mod;
    }
     
