vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin() , arr.end());
        vector<vector<int> > ans;
        for(int i=0; i<n-3; ++i)
        {
            if(i>0 && arr[i]==arr[i-1])
                continue;
            for(int j=i+1; j<n-2; ++j)
            {
                if(j>i+1 && arr[j]==arr[j-1])
                    continue;
                int tmp = arr[i]+arr[j];
                int s = j+1;
                int e = n-1;
                //if(arr[i]+arr[j]+arr[j+1]+arr[j+2]>k) break;
                //if(arr[i]+arr[j]+arr[n-2]+arr[n-1]<k) continue;
                while(s<e)
                {
                    int sum = arr[s]+arr[e]+tmp;
                    if(sum==k)
                    {
                        vector<int> vect(4);
                        vect[0] = arr[i];
                        vect[1] = arr[j];
                        vect[2] = arr[s];
                        vect[3] = arr[e];
                        ans.push_back(vect);
                        while(s<e && arr[s]==vect[2])
                            ++s;
                        while(e>s && arr[e]==vect[3])
                            --e;
                    }
                    else if(sum<k)
                        ++s;
                    else
                        --e;
                }
            }
            
        }
        return ans;
    }
