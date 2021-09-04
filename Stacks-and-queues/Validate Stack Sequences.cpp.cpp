// time - O(n)
// space - O(n)
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i1 = 0;  // for popped
        int n = pushed.size();
        stack<int> s;
        for(int i=0; i<n; ++i)
        {
            if(popped[i1] != pushed[i])
            {
                s.push(pushed[i]);
            }
            else
            {
                ++i1;
                while(i1<n && !s.empty() && (popped[i1]==s.top()) )
                {
                    s.pop();
                    ++i1;
                }
                
            }
        }
        return s.empty();
    }
