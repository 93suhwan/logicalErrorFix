#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll           long long
#define pb            push_back
#define ppb           pop_back
#define si            set <ll>
#define endl          '\n'
#define fr            first
#define sc            second
#define mii           map<ll,ll>
#define msi           map<string,ll>
#define mis           map<ll,string>
#define rep(i,a,b)    for(ll  i=a;i<b;i++)
#define all(v)        v.begin(),v.end()
#define pii           pair<ll,ll>
#define vi            vector<ll>
#define vii           vector<pair<ll,ll>>
#define vs            vector<string>
#define sz(x)         (ll)x.size()
#define rt            return
#define M             1000000007
#define bs            binary_search
#define rev(a)        reverse(all(a));
#define sp(n)         setprecision(n)
#define spl           " "
#define arr(a,n)      rep(i,0,n) cin>>a[i]
#define mod           998244353
#define time          cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define INF           1ll<<31
#define rt            return
void __prll(long x) {cerr << x;}
void __prll(long long x) {cerr << x;}
void __prll(unsigned x) {cerr << x;}
void __prll(unsigned long x) {cerr << x;}
void __prll(unsigned long long x) {cerr << x;}
void __prll(float x) {cerr << x;}
void __prll(double x) {cerr << x;}
void __prll(long double x) {cerr << x;}
void __prll(char x) {cerr << '\'' << x << '\'';}
void __prll(const char *x) {cerr << '\"' << x << '\"';}
void __prll(const string &x) {cerr << '\"' << x << '\"';}
void __prll(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __prll(const pair<T, V> &x) {cerr << '{'; __prll(x.first); cerr << ','; __prll(x.second); cerr << '}';}
template<typename T>
void __prll(const T &x) {ll f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __prll(i); cerr << "}";}
void _prll() {cerr << "]\n";}
template <typename T, typename... V>
void _prll(T t, V... v) {__prll(t); if (sizeof...(v)) cerr << ", "; _prll(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _prll(x)
#else
#define debug(x...)
#endif
/*---------------------------------------------*/
//const ll fx[]={+1,-1,+0,+0};
//const ll fy[]={+0,+0,+1,-1};
//const ll fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//const ll fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//const ll fx[]={-2, -2, -1, -1,  1,  1,  2,  2};
//const ll fy[]={-1,  1, -2,  2, -2,  2, -1,  1};
/*------------------------------------------------*/
//Things not to forget
//1)Every even number except 2 can be expressed as sum of 2 primes
//2)Every odd number greater than 5 can be expressed as sum of 3 primes
//3)Every odd number greater than 7 can be expressed as sum of 3 odd primes
//Write your Logic here
int n,m,k;
int a[1005][1005];
int c[1005];
void dfs(int i,int j)
{ 
  //cout<<i<<" "<<j<<" "<<endl;
  if(i==n)
  {
    cout<<j+1<<" ";
    return;
  }
  if(a[i][j]==1)
  {
    a[i][j]=2;
    dfs(i,j+1);
  }
  else if(a[i][j]==2)
  {
    dfs(i+1,j);
  }
  else if(a[i][j]==3)
  { 
    a[i][j]=2;
    dfs(i,j-1);
  }
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m>>k;
  rep(i,0,n)
  rep(j,0,m)
  cin>>a[i][j];
  rep(i,0,k)
  cin>>c[i];
  rep(i,0,k)
  { 
    //cout<<c[i]<<" ";
    dfs(0,c[i]-1);
  }
}
