#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;
#define trace1(x)                cerr<<#x<<": "<<x<<"\n";
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<"\n";
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"\n";
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<"\n";
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<"\n";
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<"\n";
void printMST(int parent[], vector<pair<int, int>> graph, int V)
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}
int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];

    /*int a, b, wt;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }
    trace1(N)*/

    int Parent[N];

    int key[N];

    bool mst[N];

    for (int i = 0; i < N; i++)
        mst[i] = false, key[i] = INT_MAX;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    Parent[0] = -1;
    pq.push(make_pair(0, 0));

    for (int count = 0; count < N - 1; count++)
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mst[v] == false && weight < key[v])
            {
                Parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(v, key[v]));
            }
        }
    }

    return 0;
}
