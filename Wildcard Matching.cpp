bool isMatch(string s, string p, int i, int j, int n1, int n2)
    {
        vector< vector<int> > dp(n1+1 , vector<int>(n2+1 ,0) );
        // col is the string - s
        // row is the pattern - p
        dp[0][0] = true;
        // v.v.v.v imp part of the soln !!
        // going through pattern and checking for '*'
        for(int i=1; i<=n2; ++i)
        {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        }
        for(int i = 1; i <= n1; ++i)
        {
            for(int j = 1; j <= n2; ++j)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n1][n2];
    }
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0,s.size(),p.size());
    }
