// O(n) space , O(n) time
vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> s;
        vector<long long> ans(n);
        for(int i=n-1; i>=0; --i)
        {
            if(s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                while(!s.empty() && s.top() <= arr[i])
                {
                    s.pop();
                }
                if(s.empty())
                    ans[i] = -1;
                else
                    ans[i] = s.top();
            }
            s.push(arr[i]);
        }
        return ans;
    }
