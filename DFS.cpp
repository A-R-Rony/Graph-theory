#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define MAXN 100000

vector <bool>vis; // visited array
vector<int> grp[MAXN];

void DFS(int node)
{
    vis[node] = 1;
    cout<<"curr node -> "<< node<<endl;
for(auto i:grp[node]) // visit this node's array
    {
      if(vis[i] == 0) DFS(i);
    }
}
void solve()
{
   int n,m,root;
   cin >> n >> m >> root;
 
   vis.resize(n+1,0);
for (int i = 0 ; i < m ; i++)
    { 
        int u,v;
        cin >> u >> v; 
        grp[u].pb(v);
        grp[v].pb(u); 
}
    DFS(root);
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


