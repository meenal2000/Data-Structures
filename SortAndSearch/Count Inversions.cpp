// TLE error
void combine(long long arr[],int s,int e,long long &ans,int &n)
    {
        int m = (s+e)/2;
        int i , j , k ;
        vector<long long> tmp(n);
        i = s;
        j = m+1;
        k = s;
        while(i<=m && j<=e)
        {
            if(arr[i] <= arr[j])
            {
                tmp[k++] = arr[i++];
            }
            else
            {
               tmp[k++] = arr[j++];
               ans += (m-i+1);
            }
        }
        while(i<=m)
        {
            tmp[k++] = arr[i];
                ++i;
        }
        while(j<=e)
        {
            tmp[k++] = arr[j];
            ++j;
        }
        for(i = s; i<=e; ++i)
        {
            arr[i] = tmp[i];
        }
        
    }
    void merge(long long arr[], int s, int e,long long int &ans,int &n)
    {
        if(s>=e)
            return;
        int mid = (s+e)/2;
        merge(arr,s,mid,ans,n);
        merge(arr,mid+1,e,ans,n);
        combine(arr,s,e,ans,n);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans = 0;
        int n = N;
        merge(arr,0,n-1,ans,n);
        return ans;
    }
