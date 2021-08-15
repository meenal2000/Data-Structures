// space - O(n * m) even somewhat more only
// time - O(n * (mlogm) )
vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector< vector<string> > ans;
        map<string,vector<string> > mp;
        int n = string_list.size();
        for(int i=0; i<n; ++i)
        {
            string tmp ;
            tmp = string_list[i];
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(string_list[i]);
        }
        for(auto itr : mp)
        {
            int n = itr.second.size();
            //cout << n << endl;
            vector<string> temp(itr.second);
            ans.push_back(temp);
        }
        return ans;
    }
// same complexity almost
static bool comp( pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.first == p2.first)
            return p1.second <= p2.second;
        return p1.first < p2.first;
    }
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector< vector<string> > ans;
        int n = string_list.size();
        vector< pair<string,int> > nums(n);
        for(int i=0; i<n; ++i)
        {
            string tmp(string_list[i]);
            sort(tmp.begin(),tmp.end());
            pair<string,int> p = {tmp,i};
            nums[i] = p;
        }
        sort(nums.begin(),nums.end(),comp);
        
        for(int i=0; i<n; )
        {
            int j=i;
            vector<string> tmp;
            while( j<n && nums[j].first == nums[i].first)
            {
                tmp.push_back(string_list[ nums[j].second ]);
                ++j;
            }
            i = j;
            ans.push_back(tmp);
        }
        return ans;
    }
// another approach using trie
