int minSwaps(vector<int> &nums)
	{
	    int n = nums.size();
	    int ans = 0;
	    vector<pair<int,int> > tmp(n);
	    for(int i=0; i<n; ++i)
	    {
	        tmp[i] = {nums[i] , i};
	    }
	    sort(tmp.begin() , tmp.end());
	    int c = 0;
	    for(int i=0; i<n; ++i)
	    {
	        if(tmp[i].first != nums[i])
	        {
	            swap(tmp[i],tmp[tmp[i].second]);
	            --i;
	            ++c;
	        }
	    }
	    return c;
	}
