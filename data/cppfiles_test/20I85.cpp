
#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e15+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define mod1 998244353
const int maxn=300004;
#define vpll  vector<pair<ll,ll>>
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define pob pop_back
#define lb lower_bound
#define ld long double
#define ub upper_bound
#define LB 60
#define setp(x) cout<<fixed<<setprecision(x)
#define PQ_MIN  priority_queue <ll, vector<ll>, greater<ll> >
#define setbit(x)   __builtin_popcount(x)
#define all(x) (x).begin(),(x).end()
#define pie 3.14159265358
#define enter(a)   for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a)     for(ll e: a) cout<<e<<" "; cout<<"\n";

ll power(ll n,ll p,ll m)
{
  ll r=1;
  while(p)
  {
    if(p%2){
    r=(r*n)%m;
    p--;
  }
  p=p/2;
  n=(n*n)%m;
  }
  return r;

}
int pre[405][405];
int get(int x,int y,int x1,int y1){
   return pre[x][y]+pre[x1-1][y1-1]-pre[x][y1-1]-pre[x1-1][y];

}
int convert_to_1(int x,int y,int x1,int y1){
  return (x-x1+1)*(y-y1+1)-get(x,y,x1,y1);
}
int main(){

int t;
cin >> t;
while(t--){
        int i,j,k,l,m,n;
        cin >> n >> m ;
        int a[n+1][m+1]={};
      
        for(i=1;i<=n;i++){
             string s;
             cin >> s;
            for(j=1;j<=m;j++){
              a[i][j]=s[j-1]-'0';
            }
        }
        for(i=1;i<=n;i++){
          for(j=1;j<=m;j++){
            pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+a[i][j];
          //  cout<<pre[i][j]<<" ";
          }
        //  cout<<"\n";
        }
         int ans=1e7;
        for(i=1;i<=n;i++){
          for(j=i+3;j<=m;j++){
                 int pre_mn,cur_mn;
                 pre_mn=1e7;
                 cur_mn=1e7;
                 for(k=5;k<=n;k++){

                     int pre_4=6+2*(j-i-1)-(get(k-1,j,k-3,i) +get(k,j-1,k-4,i+1)-2*get(k-1,j-1,k-3,i+1))+get(k-1,j-1,k-3,i+1); 
                     cur_mn=min(pre_mn+get(k,j-1,k,i+1),pre_4);
                     ans=min(ans,cur_mn);
                     cur_mn-=get(k,j-1,k,i+1);
                     cur_mn+=get(k,i,k,i)+get(k,j,k,j)+(j-i+1)-get(k,j-1,k,i+1);
                     pre_mn=cur_mn;

                 }
          }

        }
        cout<<ans<<"\n";

  
}


}