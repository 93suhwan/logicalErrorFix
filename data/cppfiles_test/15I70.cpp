///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           nd(a,b,c)                   mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=2e18;
const int mod=1e9+7;
const int M=12;

int a[M][M],n,m,k,b[M][M];

bool valid(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
    {
        if(a[x][y])return true;
    }
    return false;
}

void chk(int i,int j)
{
   int cnt=0;
   vector<pi>vec;
   while(1)
   {

       int x=i-cnt;
       int p=j-cnt;
       int q=j+cnt;

       if(valid(x,p) && valid(x,q))
       {
           vec.pb({x,p});
           vec.pb({x,q});
           cnt++;
       }
       else break;
   }


   cnt--;
   if(cnt>=k)
   {
      for(auto z:vec)
      {
          b[z.fi][z.si]=1;
      }
   }

}
void solve()
{
   cin>>n>>m>>k;

   f(i,1,n)
   {
      string s;
      cin>>s;
      f(j,1,m)
      {
          if(s[j-1]=='*')a[i][j]=1;
          else a[i][j]=0;

          b[i][j]=0;
      }
   }

   f(i,1,n)
   {
       f(j,1,m)
       {
           if(a[i][j])
           {
               chk(i,j);
           }
       }
   }

   f(i,1,n)
   {
       f(j,1,m)
       {
           if(a[i][j]!=b[i][j])
           {
               cout<<"NO\n";return ;
           }
       }
   }

   cout<<"YES\n";
}

 main()

{
    fast
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;

}



































