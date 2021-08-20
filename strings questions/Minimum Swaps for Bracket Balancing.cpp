// O(n) space , O(n) time
//  ] ] ] [ [
//  1 0 -1 
// pos - 3 , 4
// cnt = -1
//  ans += 3 - 0
int minimumNumberOfSwaps(string x){
    
    int n = x.size();
    int cnt = 0; // stores the current count factor of [ , ]
    int ans = 0;
    vector<int> pos;
    for(int i = 0; i < n; ++i)
    {
        if(x[i] == '[')
            pos.push_back(i);
    }
    int ind = 0;
    for(int i = 0; i < n; ++i)
    {
        if(x[i] == '[')
        {
            ++cnt;
            ++ind;
        }
        else
        {
            --cnt;
            if(cnt < 0)
            {
                ans += pos[ind] - i;
                swap(x[i],x[pos[ind]]);
                ++ind;
                cnt =1;
            }
        }
    }
    return ans;
    }
// O(1) space
// O(n) time
int minimumNumberOfSwaps(string x){
    int n = x.size();
    int ans = 0;
    int open = 0;
    int close = 0;
    int fault = 0;
    for(int i = 0; i < n; ++i)
    {
        if(x[i] == ']')
        {
            ++close;
            fault = close - open;
        }
        else
        {
            ++open;
            if(fault > 0)
            {
                ans += fault;
                fault--;
            }
        }
    }
    return ans;
    }
