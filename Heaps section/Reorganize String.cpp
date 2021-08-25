// using heaps
// O(n * log(n) )
string reorganizeString(string s) {
        int n = s.size();
        string ans;
        ans = s; // init purpose only
        map<char,int> mp;
        for(int i=0; i<n; ++i)
        {
            mp[s[i]]++;
        }
        priority_queue< pair<int,char> > p;
        for(auto itr = mp.begin(); itr!=mp.end(); ++itr)
        {
            char ch = itr -> first;
            int f = itr -> second;
            //cout << f << " " << ch << " ";
            p.push({f, ch});
        }
        int idx;
        char ch = p.top().second;
        int f = p.top().first; 
        p.pop();
        //cout << f << " " << ch << " " << (n+1)/2 << endl;
        if( f > (n+1)/2)
            return "";
        int i;
        for(i=0; f ; i+=2 , --f)
        {
            ans[i] = ch;
        }
        while(!p.empty())
        {
            ch = p.top().second;
            f = p.top().first; 
            p.pop();
            while(f)
            {
                if(i >= n)
                    i = 1;
                ans[i] = ch;
                f--;
                i += 2;
            }
        }
        return ans;
    }
