// time - O(n^2)
// by greedy it wont always give optimal answer , hence greedy
// dry run for [ 3, 2, 2, 5]
int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        int cost;
        dp[n-1] = 0;
        for(int i=n-2; i>=0; --i)
        {
            int len = -1;
            for(int j=i; j<n; ++j)
            {
                len += nums[j]+1;
                if(len > k)
                    break;
                if( j == n-1)
                    cost = 0;
                else
                    cost = (k-len)*(k-len) + dp[j+1];
                
                if(dp[i] > cost)
                {
                    dp[i] = cost;
                }
            }
            //cout << dp[i] << endl;
        }
        return dp[0];
    } 
// through recursion
int solve(vector<int> &nums, int k, vector<int> &dp, int n, int i,int len)
    {
        if(i < 0)
            return dp[i+1];
        int cost;
        for(int j=i; j<n; ++j)
        {
            len += nums[j] + 1;
            if(len > k)
                break;
            if(j==n-1)
               cost = 0;
            else
                cost = (k-len)*(k-len) + dp[j+1];
            if(dp[i] > cost)
            {
                dp[i] = cost;
            }
        }
        //cout << dp[i] << endl;
        return solve(nums,k,dp,n,i-1,-1);
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1] = 0;
        return solve(nums, k, dp, n, n-2 ,-1);
    } 
