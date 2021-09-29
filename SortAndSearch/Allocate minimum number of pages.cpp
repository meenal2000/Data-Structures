// O(nlogn) binary search
int findPages(int A[], int N, int M) 
    {
        if(M > N)
            return -1;
        int ans = INT_MAX;
        long long int s , e = 0 , sum = 0 , cnt = 0 , m;
        //sort(A,A+N);
        s = A[0];
        for(int i=0; i<N; ++i)
            e += A[i];
        while(s <= e)
        {
            m = (s+e)/2;
            cnt = 1;
            sum = 0;
            for(int i=0; i<N; ++i)
            {
                if(A[i] > m)
                {
                    cnt = M+1;
                    break;
                }
                if(A[i]+sum <= m)
                {
                    sum+= A[i];
                }
                else
                {
                    ++cnt;
                    sum = A[i];
                }
            }
            if(cnt <= M)
            {
                ans = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        return ans;
    }
