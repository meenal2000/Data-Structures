// O(n)
bool ispar(string x)
    {
        stack<char> s;
        int i=0;
        int n = x.size();
        while(i < n)
        {
            if(s.empty() || x[i]=='[' || x[i]=='{' || x[i]=='(')
                s.push(x[i]);
            else if(x[i] == ']' && s.top()=='[')
                s.pop();
            else if(x[i] == ')' && s.top()=='(')
                s.pop();
            else if(x[i] == '}' && s.top()=='{')
                s.pop();
            else
                s.push(x[i]);
            ++i;
        }
        return s.empty();
        
    }
