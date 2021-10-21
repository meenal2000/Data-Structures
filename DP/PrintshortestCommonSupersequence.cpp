// It's the same as printing LCS 
// Just a small change that in SCS , u have to consider the case when one string empties and another does'nt and u still add cause it's SCSSSSSSS
string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector< vector<int> > dp (n1+1 , vector<int>(n2+1 , 0));
        for(int i=1; i<=n1; ++i)
        {
            for(int j=1; j<=n2; ++j)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        int i=n1; int j=n2;
        string ans = "";
        while(i>0 && j>0)
        {
            if(s1[i-1] == s2[j-1])
            {
                ans += s1[i-1];
                --i;
                --j;
            }
            else
            {
                if(dp[i-1][j] >= dp[i][j-1])
                {
                    ans += s1[i-1];
                    --i;
                }
                else
                {
                    ans += s2[j-1];
                    --j;
                }
            }
        }
        while(i>0)
        {
            ans += s1[i-1];
                --i;
        }
        while(j>0)
        {
            ans += s2[j-1];
                --j;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
