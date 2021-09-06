vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<int,int> > q;
	    for(int i=0; i<n; ++i)
	    {
	        for(int j=0; j<m; ++j)
	        {
	            if(grid[i][j])
	                q.push({i,j});
	        }
	    }
	    int dx[4] = {0,0,-1,1};
	    int dy[4] = {1,-1,0,0};
	    while(!q.empty())
	    {
	        int k = q.size();
	        while(k--)
	        {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            for(int i=0; i<4;++i)
	            {
	                int nx = x+dx[i];
	                int ny = y+dy[i];
	                if(nx<0 || nx>=n || ny<0 ||ny>=m || grid[nx][ny]!=0)
	                    continue;
	                grid[nx][ny] = grid[x][y]+1;
	                q.push({nx,ny});
	            }
	        }
	    }
	    for(int i=0; i<n; ++i)
	    {
	        for(int j=0; j<m; ++j)
	        {
	            grid[i][j]--;
	        }
	    }
	    return grid;
	}
