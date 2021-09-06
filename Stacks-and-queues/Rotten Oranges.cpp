int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue< pair<int,int> > q;
        int tot = 0;
        int cnt = 0;
        int days = 0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(grid[i][j] != 0)
                {
                    ++tot;
                }
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0};
        while(!q.empty())
        {
            int k = q.size();
            cnt += k;
            while(k--)
            {
                int nx = q.front().first;
                int ny = q.front().second;
                q.pop();
                for(int i=0; i<4; ++i)
                {
                    int x = nx+dx[i];
                    int y = ny+dy[i];
                    if(x<0 || x>=n || y<0 || y>=m || grid[x][y]!=1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x,y});
                }

            }
            if(!q.empty())
                ++days;
        }
        //cout << "tot = " << tot << " cnt = " << cnt << "\n";
        return tot==cnt ? days : -1;
    }
