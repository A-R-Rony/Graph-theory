#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define en "\n"
#define dbg cout<<"rony\n";

#define MAXN 300010

vector<int>g[MAXN];
int vis[MAXN];

bool dfs(int nd)
{
    bool ok = false;
    vis[nd] = 1;
    for(auto i:g[nd]){
        if(vis[i] == 0) {
            ok |= dfs(i);
        }
        else if(vis[i] == 1) return true;
    }
    vis[nd] = 2;
    return ok;
}
void solve()
{
   int n,m;
   cin >> n >> m;
   for(int i = 1;i <= m;i++){
    int x,y;
    cin >> x >> y;
    g[x].pb(y);
   }

   bool cycle = false;

   for(int i = 1;i <= n;i++){
       cycle |= dfs(i);
   }

   if(cycle) cout<<"Cycle founded in this directed graph\n";
   else cout<<"No cycle founded in this directed graph\n";
}
int main()
{

   int t;
   t = 1;

    while ( t-- )
    {
        solve();
    }
    return 0;
}
