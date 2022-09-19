#include<bits/stdc++.h>
using namespace std;

#define MAXN 100
vector<int>g[MAXN];
int vis[MAXN];
vector<int>v;

void dfs(int nd)
{
    vis[nd] = 1;
    v.push_back(nd);

    for(auto i:g[nd])
    {
        if(vis[i] == 1) continue;
        dfs(i);
    }
}
int main()
{
   int n,m;
   cin >> n >> m;
   for(int i = 1;i <= m;i++)
   {
     int x,y;
     cin >> x >> y;
     g[x].push_back(y);
     g[y].push_back(x);
   }

   dfs(1);
   // travase order
   for(auto i:v) cout<<i<<" ";cout<<endl;

}
