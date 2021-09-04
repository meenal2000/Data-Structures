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
    
