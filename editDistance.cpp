// through recursion - O(3^n)
// through dp - O(n*n)
int editDistance(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector< vector<int> > dp(n1+1, vector<int> (n2+1));
        for(int i=0; i<=n1; ++i)
            dp[i][0] = i;
        for(int j=0; j<=n2; ++j)
            dp[0][j] = j;
        for(int i=1; i<=n1; ++i)
        {
            for(int j=1; j<=n2; ++j)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                }
            }
        }
        return dp[n1][n2];
    }
