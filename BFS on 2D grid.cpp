#include<bits/stdc++.h>
using namespace std;

        /// BISMILLHIR RAHMANIR RAHIM
///------------------------------------------------------------

char a[25][25];
int vis[25][25];

int n,m;
int ans;

int step[4][2]={1,0,-1,0,0,1,0,-1};

bool isvalid(int x,int y)
{
    if(x>= 0 && y >= 0 && x < m && y < n && vis[x][y] == 0 && a[x][y] == '.') return true;
    return false;
}

void bfs(int x,int y)
{
    queue<int>qx;
    queue<int>qy;

    qx.push(x);
    qy.push(y);
    
    vis[x][y] = 1;
    ans++;



    while(!qx.empty())
    {
        int tx = qx.front();
        int ty = qy.front();

        qx.pop(); qy.pop();

         for(int i = 0 ;i < 4;i++){

          int nx = tx + step[i][0];
          int ny = ty + step[i][1];

          if(isvalid(nx,ny)){
            ans++;
             vis[nx][ny] = 1;
             qx.push(nx);
             qy.push(ny);
          }
       }

    }

   
}

void solve()
{
    ans = 0;
    memset(vis,0,sizeof(vis));
   
   scanf("%d%d",&n,&m);
    
   for(int i = 0 ;i < m ;i++)
   {
      scanf("%s",a[i]);
   }

   int p,q;
   bool ok = false;


   for(int i = 0 ;i < m && !ok;i++){
    for(int j = 0 ; j < n;j++){
        if(a[i][j] == '@'){
           
            p = i,q = j;
            ok = true;
            break;
        }
    }
   }

   bfs(p,q);

   printf("%d\n",ans);
   
} 

int main()
{
    int t;

     scanf("%d",&t);
     for(int i = 1; i <= t ; i++){
        printf("Case %d: ",i);

        solve();
     }
    return 0;
}
   /// A L H A M D U L I L L A H
