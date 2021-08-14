// abc
// 0 1 2
// 0 0 0 ""
// 0 0 1 c
// 0 1 0 b
// 0 1 1 bc

#include <bits/stdc++.h>
using namespace std;
// Through recursion
void solve(string s , int i,int n,string op, vector<string> &ans){
    if(i==n)
    {
        ans.push_back(op);
        return;
    }
    solve(s,i+1,n,op+s[i],ans);
    solve(s,i+1,n,op,ans);
}
int main() {
    string s;
    cin >> s;
    string op;
    vector<string> ans;
	solve(s,0,s.size(),op,ans);
	for(int i=0; i<ans.size(); ++i)
	{
	    cout << ans[i] << " ";
	}
	cout << endl << ans.size();
	return 0;
}

// Through iteration
void solve(string s , int n, vector<string> &ans){
    
    for(int i=0; i<(1<<n); ++i)
    {
        int x = i;
        string op = "";
        int k=0;
        while(x)
        {
            if(x & 1)
            {
                op += s[k];
            }
            k++;
            x = x >> 1;
        }
        ans.push_back(op);
    }
}
int main() {
    string s;
    cin >> s;
    string op;
    vector<string> ans;
	solve(s,s.size(),ans);
	for(int i=0; i<ans.size(); ++i)
	{
	    cout << ans[i] << " ";
	}
	cout << endl << ans.size();
	return 0;
}
