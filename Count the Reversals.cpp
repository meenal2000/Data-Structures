// Count the Reversals
// space - O(n)
// space - O(1) also exists in which u keep two vars left_brace, right_brace 
// if opening then , l++, else for '}' => check if l>0 , l-- ,  else ++r;
// return ceil(l/2.0)+ceil(r/2.0);
int countRev (string x)
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
    if( s.size() % 2 != 0)
        return -1;
    if(s.empty())
        return 0;
    int m = 0;  n=0;
    while(!s.empty())
    {
        char ch = s.top();
        if(ch=='{' || ch=='[' || ch=='(')
            ++m;
        else
            ++n;
        s.pop();
    }
   // cout << m << " " << n << endl;
    return ceil(m/2.0) + ceil(n/2.0);
}
