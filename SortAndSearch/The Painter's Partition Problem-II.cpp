// O(nlogn)
long long minTime(int arr[], int n, int painters)
    {
        long long sum = 0 , ans=LONG_MAX ;
        for(int i=0; i<n; ++i)
            sum += arr[i];
        long long s = arr[0];
        long long e = sum;
        while(s <= e)
        {
            long long m =(s+e)/2;
            long long cnt = 1;
            sum = 0;
            for(int i=0; i<n; ++i)
            {
                if(arr[i] > m)
                {
                    cnt = painters+1;
                    break;
                }
                if(arr[i]+sum <= m)
                {
                    sum += arr[i];
                }
                else
                {
                    sum = arr[i];
                    ++cnt;
                }
            }
            if(cnt <= painters)
            {
                ans = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        return ans;
    }
