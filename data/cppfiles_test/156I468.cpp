#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; //https://codeforces.com/blog/entry/11080
//find_by_order(k) : returns an iterator to the k-th largest element (counting from zero)
//order_of_key(k) : number of elements in set that are strictly smaller than k 
typedef long long                ll;
typedef long double              ld;
typedef pair<int, int>           pii;
typedef pair<ll,ll>              pll;
typedef pair<ld,ld>              pld;
typedef vector<int>              vi;
typedef vector<ll>               vll;
typedef vector<ld>               vld;
typedef vector<pii>              vpi;
typedef vector<pll>              vpl;

#define rep(i,a,b)               for(int i=a;i<b;i++)
#define rrep(i,a,b)              for(int i=b-1;i>=a;i--)
#define endl                     '\n'
#define google(x)                cout<<"Case #"<<x<<": ";
#define sz(x)                    (int)(x).size()
#define mp                       make_pair
#define pb                       push_back
#define pob                      pop_back
#define ff                       first
#define ss                       second
#define lb                       lower_bound
#define ub                       upper_bound
#define all(x)                   x.begin(), x.end()
#define mem(a,x)                 memset(a,x,sizeof(a))
#define ins                      insert
#define mod                      1000000007
#define MOD1                     998244353
#define fast_io                  cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);
// const long long N=(long long)(1e5+5);
// const long long inf=(long long)(1e18);
void solve();
void init_code(){
   fast_io;
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif 
}

int main() {
   init_code();
   int t = 1;
   cin>>t;
   while(t--){
      solve();
   }
  return 0;
}

void solve()
{
   int n;ll k;
   cin>>n>>k;
   vll a(n),prefsum(n+1,0);

   for(auto &p : a) cin>>p;
   sort(all(a));
   rep(i,0,n) prefsum[i+1]=prefsum[i]+a[i];
   
   ll ans=(ll)1e18;
   for(int t=0;t<n;t++){
      ll sum=prefsum[n-t] + t*a[0];
      ll temp=t;
      if(sum>k){
         // temp+=(sum-k+t)/(t+1);
         //plus t in order to get the ceil value. if temp=1.5, we want 2
         temp+=ceil((float)(sum-k)/(t+1));
      }
      ans=min(ans,temp);
   }
   cout<<ans<<endl;
}
