#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

typedef pair<int,int>pr;
#define mp   make_pair
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb push_back
#define eps 1e-9
#define SP cout<<fixed<<setprecision(10);

        /// BISMILLHIR RAHMANIR RAHIM
///------------------------------------------------------------

#define inf 100000
#define MAXN 110
int cnt [ MAXN+1];
const int mod = 1e9+7;

vector<int>grp[MAXN];
int col[MAXN];
int vis[MAXN];

void dfs(int node)
{
    vis[node] = 1;
    for(auto i:grp[node])
    {
        if(vis[i] == 0)
            dfs(i);
    }
}

void solve()
{
    int pub = 0;
   int n,m;
   cin >> n >> m;
   for(int i = 1; i<= n;i++){
    int k;
    cin >> k;
    if(k == 0) pub++;

    int a[k];

    for(int j = 0 ;j < k;j++)
    cin >> a[j],col[a[j]] = 1;
   
    for(int j = 0; j< k;j++){
       for(int l = 0; l < k; l++){
        if(l == j) continue;
        grp[a[j]].pb(a[l]);
       }
    }
   }
   

   int cc = 0;
   for(int i = 1; i<=m;i++)
   {
     if(col[i] == 1 && vis[i] == 0){
        dfs(i);
        cc++;
     }
   }
   int res = cc - 1;
   if(res < 0) res = 0;
   res += pub;

   
   cout<<res<<endl;



}
int main()
{
    IOS;
    int t;
    t = 1;
    //cin >> t;
    while ( t-- )
        solve();
    return 0;
}
   /// A L H A M D U L I L L A H
