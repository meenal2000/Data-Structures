int minCoins(int coins[], int M, int V) 
	{ 
	   int dp[M+1][V+1];
	   for(int i=0; i<=V; ++i)
	        dp[0][i] = INT_MAX-1; // we are storing -1 here, because if at all it gets in the dp formula then, while doing +1 we don't go out of bound
	   for(int i=0; i<=M; ++i)
	        dp[i][0] = 0;
	   for(int i=1; i<=V; ++i)
	   {
	       if(i%coins[0] == 0)
	        dp[1][i] = i / coins[0];
	       else
	        dp[1][i] = INT_MAX-1;
	   }
	   for(int i=2; i<=M; ++i)
	   {
	       for(int j=1; j<=V; ++j)
	       {
	           if(coins[i-1] > j)
	                dp[i][j] = dp[i-1][j];
	           else
	           {
	               dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1); // +1 since we are considering that coin in the answer
	           }
	       }
	   }
	   return dp[M][V] == INT_MAX-1 ? -1 : dp[M][V];
	} 
