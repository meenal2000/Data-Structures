// O(n) time and space
string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int n1 = t.size();
        int n2 = s.size();
        for(int i=0; i<n1; ++i)
        {
            mp[t[i]]++;
        }
        int start = 0;
        int cnt = 0; // current window length
        int min_start = -1;
        int len = INT_MAX; // stores the final length of the window
        for(int i=0; i<n2; ++i)
        {
            if(mp.find(s[i]) != mp.end())
            {
                mp[s[i]]--;
                if(mp[s[i]] >= 0)
                {
                    ++cnt;
                }
            }
            
           //cout << cnt << " " << n1 << endl;
            while( cnt == n1 )
            {
                // save the length
                if(len > i-start+1)
                {
                    len = i-start+1;
                    min_start = start; 
                }
                // remove an eligible character
                if(mp.find(s[start]) != mp.end())
                {
                    mp[s[start]]++;
                    if(mp[s[start]] > 0)
                    {
                        --cnt;
                    }
                }
                ++start;
            }
        }
        return min_start==-1 ? "" : s.substr(min_start,len);
    }
