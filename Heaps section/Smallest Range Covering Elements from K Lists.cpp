// O( maxcolSize * log(numRows) )
struct comp {
        bool operator() (pair <int,pair<int,int> > &p1, pair <int,pair<int,int> > &p2)
        {
            return p1.first > p2.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue< pair < int , pair< int,int >> , vector<pair < int , pair< int,int >>>, comp > pq;
        int low;
        int high = INT_MIN;
        for(int i=0; i<n; ++i)
        {
            pq.push( { nums[i][0], {i,0} } );
            high = max(high , nums[i][0]);
        }
        low = pq.top().first;
        vector<int> res{low,high};
        while(pq.size() == n)
        {
            int i = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(c+1 < nums[i].size())
            {
                pq.push( {nums[i][c+1] , {i,c+1} } );
                high = max(high , nums[i][c+1] );
                low = pq.top().first;
                if(high - low < res[1] - res[0])
                {
                    res[1] = high;
                    res[0] = low;
                }
            }
        }
        return res;
    }
