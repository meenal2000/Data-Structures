 // same as MCM 
// Just a few variation here and there
int dp[202][202][2];
    int solve(string &s, int i,int j,bool ok)
    {
        if(i > j)
            return 0;
        if(i==j)
        {
            if(ok)
                return (s[i] == 'T');
            else
                return (s[i] == 'F');
        }
       if(dp[i][j][ok] != -1)
            return dp[i][j][ok];
        int ans = 0;
        for(int k=i; k<=j-1; ++k)
        {
            if(s[k]=='^' || s[k]=='|' || s[k]=='&')
            {
                int leftT = solve(s,i,k-1,1);
                int leftF = solve(s,i,k-1,0);
                int rightT = solve(s,k+1,j,1);
                int rightF = solve(s,k+1,j,0);
                if(s[k] == '|')
                {
                    if(ok)
                       ans += (leftT*rightT)+(leftT*rightF)+(leftF*rightT);
                    else
                        ans += (leftF*rightF);
                }
                if(s[k] == '^')
                {
                    if(ok)
                        ans += (leftT*rightF)+(leftF*rightT);
                    else
                        ans += (leftT*rightT)+(leftF*rightF);
                }
                if(s[k] == '&')
                {
                    if(ok)
                        ans += (leftT*rightT);
                    else
                       ans += (leftF*rightF)+(leftT*rightF)+(leftF*rightT); 
                }
                    
            }
        }
        return dp[i][j][ok] = ans%(1003);
    }
    int countWays(int N, string S){
       memset(dp,-1,sizeof(dp));
        return solve(S , 0 , N-1,1);
    }
