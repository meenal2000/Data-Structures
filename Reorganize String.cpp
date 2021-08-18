// space - O(n)
// time - O(n)
// u could also do without map
// u could also use priority queue since u have to order acc. to max chars
string reorganizeString(string s) {
        int n = s.size();
        string ans;
        ans = s; // init purpose only
        map<char,int> mp;
        for(int i=0; i<n; ++i)
        {
            mp[s[i]]++;
        }
        int len = 0;
        char letter;
        for(auto itr = mp.begin(); itr!=mp.end(); ++itr)
        {
            if(itr->second > len)
            {
                len = itr->second;
                letter = itr->first;
            }
        }
        if(len > (n+1)/2 )
            return "";
        int idx = 0;
        while(len)
        {
            ans[idx] = letter;
            idx += 2;
            --len;
        }
        mp[letter] = 0;
        for(auto itr = mp.begin(); itr!=mp.end(); ++itr)
        {
            while(itr->second)
            {
                if(idx >= n)
                    idx = 1;
                ans[idx] = itr->first;
                itr->second--;
                idx += 2;
            }
        }
        return ans;
    }
