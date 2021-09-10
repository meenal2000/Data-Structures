// time - O(n) , space - O(n)
int FindMaxSum(int arr[], int n)
    {
        if(n == 1)
            return arr[0];
        if(n==2)
            return max(arr[0] , arr[1]);
        int dp[n];
        dp[0] = arr[0];
        dp[1] = max(arr[0] , arr[1]);
        for(int i=2; i<n; ++i)
        {
            dp[i] = max(dp[i-1] , arr[i]+dp[i-2]);
        }
        
        return dp[n-1];
    }
// time - O(n) , space - O(1)
int FindMaxSum(int arr[], int n)
    {
        if(n == 1)
            return arr[0];
        if(n == 2)
            return max(arr[0] , arr[1]);
        int incl = arr[0];
        int excl = 0;
        int tmp;
        for(int i=1; i<n; ++i)
        {
            tmp = excl;
            excl = max(incl , excl);
            incl = max(tmp+arr[i] , tmp);
        }
        
        return max(incl,excl);
    }
