int evaluatePostfix(string str)
    {
        stack<int> s;
        int n = str.size();
        for(int i=0; i<n; ++i)
        {
            if(isdigit(str[i]))
            {
                s.push(str[i]-'0');
            }
            else
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int ans ;
                if(str[i]=='*')
                    ans = num2 * num1;
                if(str[i]=='/')
                    ans = num2 / num1;
                if(str[i] == '+')
                    ans = num2 + num1;
                if(str[i] == '-')
                    ans = num2 - num1;
                s.push(ans);
            }
        }
        return s.top();
    }
