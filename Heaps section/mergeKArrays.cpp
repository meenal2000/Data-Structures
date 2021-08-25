struct compare{
       bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
       {
           return a.first>b.first;
       }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> q;
       for(int i=0;i<k;++i)
           q.push( {arr[i][0],{i,0} } );
       vector<int> ans;
       while(!q.empty())
       {
           int val=q.top().first;
           int row=q.top().second.first;
           int index=q.top().second.second;
           q.pop();
           ans.push_back(val);
           if(index<k-1)
             q.push(make_pair(arr[row][index+1],make_pair(row,index+1)));
       }


       return ans;
    }
