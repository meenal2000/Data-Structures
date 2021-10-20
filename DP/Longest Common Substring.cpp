int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector< vector<int> > dp(n+1, vector<int>(m+1,0));
        int ans = 0;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                if(S1[i-1] == S2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return ans;
    }
