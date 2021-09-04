// O(n) time and space 
int findMaxLen(string str) {
        int n = str.size();
        int res = 0;
        stack<int> s;
        s.push(-1);
        for(int i=0; i<n; ++i)
        {
            if(str[i] == ')')
            {
                if(!s.empty())
                    s.pop();
                if(!s.empty())
                    res = max(res, i - s.top());
                else
                    s.push(i);
            }
            else
            {
                s.push(i);
            }
        }
        return res;
    }
    
// O(n) time , O(1) space
int findMaxLen(string str) {
        int n = str.size();
        int res = 0;
        int l=0;
        int r=0;
        for(int i=0; i<n; ++i)
        {
            if(str[i] == ')')
                ++r;
            else
                ++l;
            if(r > l)
            {
                r = 0;
                l = 0;
            }
            if(r==l)
                res = max(res , 2*l);
        }
        r = 0; l = 0;
        for(int i=n-1; i>=0; --i)
        {
            if(str[i] == ')')
                ++r;
            else
                ++l;
            if(l > r)
            {
                r = 0;
                l = 0;
            }
            if(r==l)
                res = max(res , 2*l);
        }
        return res;
    }
