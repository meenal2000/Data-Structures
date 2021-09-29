// we can do O(n2) , by travelling for all distances from 1 to n
// we can also do binary search to find the maximum of the minimum distance
// Author - Meenal gupta
#include <bits/stdc++.h>
using namespace std;
#define trace1(x)                cerr<<#x<<": "<<x<<"\n";
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n";
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n";
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n";
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<"\n";
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<"\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define N 1e8+5
#define ll long long int

int main()
{
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n , c;
        cin >> n >> c;
        vector<ll> pos(n);
        for(int i=0; i<n; ++i)
        {
            cin >> pos[i];
        }
        sort(pos.begin() , pos.end());
        ll s = 0;
        ll e = pos[n-1] - pos[0];
        ll ans = LONG_MIN;
        while( s <= e)
        {
            ll m = (s+e)/2;
            int cnt = 1;
            int prev= pos[0];
            for(int i=1; i<n && cnt < c; ++i)
            {
                if(pos[i] - prev >=m)
                {
                    ++cnt;
                    prev = pos[i];
                }
            }
            //trace2(m, cnt)
            if(cnt == c)
            {
                ans = max(ans , m);
                s = m+1;
            }
            else
            {
                e = m-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
