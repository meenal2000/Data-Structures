int dp[505][505];
    bool isPalindrome(string &s , int i, int j)
    {
        while(i<=j)
        {
            if(s[i] == s[j])
            {
                ++i;
                --j;
            }
            else
                return false;
        }
        return true;
    }
    int solve(string &s , int i , int j)
    {
        if( i >= j )
            return 0;
        if( isPalindrome(s,i,j) )
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for(int k=i; k<=j-1; ++k)
        {
            int left , right;
            if( dp[i][k] != -1)
                left = dp[i][k];
            else 
                left = solve(s,i,k);
            if( dp[k+1][j] != -1)
                right = dp[k+1][j];
            else 
                right = solve(s,k+1,j);
            int tmp =  left + right + 1;
            mn = min(tmp,mn);
        }
        return dp[i][j] = mn;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        memset(dp,-1,sizeof(dp));
        return solve(str , 0 , n-1);
    }
