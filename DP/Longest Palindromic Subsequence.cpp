// same as LCS
// Just reverse the original string and find the LCS btw the two
// the original property is always fulfilled that of palindrome 
// that is as soon as we found a match 
// we look for another match till i-1, j-1
// and since string is reversed we can ensure , the palindromic property of i , n-i-1 alwyas holds true and that new pair is inside another pair
int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin() , t.end());
        int n = s.size();
        vector< vector<int> > dp(n+1 , vector<int>(n+1 , 0));
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
