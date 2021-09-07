// O(n + (klogn) + (nlogk )
// O(n) - space
int minValue(string s, int k){
        map<int,int> mp;
        int n = s.size();
        if( k >= n)
            return 0;
        for(int i=0; i<n; ++i)
        {
            mp[s[i]]++;
        }
        priority_queue<int> q; // max heap by default
        int ans = 0;
        for(auto &c: mp)
        {
            q.push(c.second);
        }
        while(k--)
        {
            int tmp = q.top();
            tmp--;
            q.pop();
            q.push(tmp);
        }
        while(q.size())
        {
            int tmp = q.top();
            q.pop();
            ans += (tmp)*(tmp);
        }
        return ans;
    }
