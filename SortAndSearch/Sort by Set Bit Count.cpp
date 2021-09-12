static bool comp(pair< pair<int,int> , int> p1,pair< pair<int,int> , int>p2)
    {
        int x1 = p1.first.first;
        int x2 = p2.first.first;
        if(x1 != x2)
            return x1 > x2;
        x1 = p1.first.second;
        x2 = p2.first.second;
        return x1 < x2;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair< pair<int,int> , int> > vect(n);
        for(int i=0; i<n; ++i)
        {
            int tmp = arr[i];
            int c = 0;
            while(tmp)
            {
                if(tmp&1)
                    ++c;
                tmp = tmp >> 1;
            }
            vect[i] = { {c,i} , arr[i] };
        }
        sort(vect.begin(),vect.end(),comp);
        int k = 0;
        for(auto &x: vect)
        {
            arr[k++] = x.second;
        }
        
    }
