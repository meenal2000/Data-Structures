vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long int p = 1;
        long long int cnt = 0;
        for(int i=0; i<n; ++i)
        {
            if(nums[i])
                p *= nums[i];
            else
                ++cnt;
        }
        vector<long long int> ans(n);
        for(int i=0; i<n; ++i)
        {
            if(cnt > 1)
                ans[i] = 0;
            else
            {
                if(cnt)
                {
                    if(nums[i])
                        ans[i] = 0;
                    else
                        ans[i] = p;
                }
                else
                {
                    ans[i] = p / nums[i];
                }
            }
        }
        return ans;
    }
