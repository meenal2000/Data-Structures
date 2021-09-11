https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#

long long countTriplets(long long arr[], int n, long long x)
	{
	    long long ans = 0;
	    sort(arr,arr+n);
	    for(int i=0; i<n-2; ++i)
	    {
	        for(int j=i+1; j<n-1; ++j)
	        {
	            int s = j+1;
	            int e = n-1;
	            long long sum = arr[i] + arr[j];
	            if(sum+arr[s]>=x)
	                continue;
	            int k = n;
	            while(s <= e)
	            {
	                int m = (s+e) / 2;
	                if(sum + arr[m] >= x)
	                    e = m-1;
	                else
	                {
	                    k = m;
	                    s = m+1;
	                }
	            }
	            if(k!=n)
	            {
	                ans += (k-j);
	            }
	        }
	    }
	    return ans;
	}
