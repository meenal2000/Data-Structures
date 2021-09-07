// O(n2) approach
// O(n) approach
// O(1) approach
queue<long long> q;
        for(long long int i=0; i<K; ++i)
        {
            if(A[i]<0)
                q.push(i);
        }
        vector<long long> ans;
        
        for(long long int i=K; i<N; ++i)
        {
            if(!q.empty())
                ans.push_back(A[q.front()]);
            else
                ans.push_back(0);
            while(!q.empty() && q.front()<(i-K+1))
            {
                q.pop();
            }
            if(A[i]<0)
                q.push(i);
        }
        if(!q.empty())
            ans.push_back(A[q.front()]);
        else
            ans.push_back(0);
        return ans;
// Alternate O(n)
queue<long long> q;
        for(long long int i=0; i<K; ++i)
        {
            q.push(A[i]);
        }
        vector<long long> ans;
        while(!q.empty() && q.front()>=0)
        {
            q.pop();
        }
        if(!q.empty())
            ans.push_back(q.front());
        else
            ans.push_back(0);
        for(long long int i=K; i<N; ++i)
        {
            q.push(A[i]);
            while(!q.empty() && q.size()>K)
            {
                q.pop();
            }
            while(!q.empty() && q.front()>=0)
            {
                q.pop();
            }
            if(!q.empty())
                ans.push_back(q.front());
            else
                ans.push_back(0);
        }
        return ans;
// o(1)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        int ind = 0; // first neg index of window
        int ele ; // neg ele of that window
        
        vector<long long> ans;
        
        for(long long int i=K-1; i<N; ++i)
        {
            while( (ind<i) && (ind<=i-K || A[ind]>=0))
            {
                ++ind;
            }
            if(A[ind]<0)
            {
                ans.push_back(A[ind]);
            }
            else
                ans.push_back(0);
        }
        
        return ans;
 }
