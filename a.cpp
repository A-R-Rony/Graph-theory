#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define MAXN 100000

vector <bool>vis; // visited array

vector<int>grp[MAXN];
vector<int>dist;
 int n,m,root;
 
void BFS(int node)
{
    queue<int>q;
    
    dist.clear();
    vis.clear();
    vis.resize(n+1,0);
    dist.resize(n+1, INT_MAX/2);
    
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto i:grp[u])
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }
       for(int i=1;i<=n;i++)
    {
        cout<<"distance from root to "<<i<<" is = "<<dist[i]<<endl;
    }
}
void solve()
{
  
   cin >> n >> m >> root;
 
for (int i = 0 ; i < m ; i++)
    { 
        int u,v;
        cin >> u >> v; 
        grp[u].pb(v);
        grp[v].pb(u); 
}
    BFS(root);
}
int main()
{
   
    int t;
    t = 1;
    // cin >> t;
    while ( t-- )
        solve();
    return 0;
}
 

