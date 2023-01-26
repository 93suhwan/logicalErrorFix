#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define L list
#define V vector
#define MS multiset
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false), cin.tie(0);
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void solve(){
   ll n;
   cin>>n;
   V<V<ll>>a(n+1);
   for(int i=1;i<=n;++i){
      ll ci;
      cin>>ci;
      a[i] = V<ll>(ci+1,LONG_LONG_MIN);
      for(int j=1;j<=ci;++j)cin>>a[i][j];
   }
   map<V<ll>,bool>vis;
   ll m;
   cin>>m;
   for(int i=0;i<m;++i){
      V<ll>put(n);
      for(int j=0;j<n;++j){
         cin>>put[j];
      }
      vis[put] = 1;
   }
   V<ll>ans(n);
   for(int i=0;i<n;++i){
      ans[i] = a[i+1].size()-1;
   }
   while(vis[ans]==1){
      // cout << "yo\n";
      ll mn = LONG_LONG_MAX;
      ll idx = -1;
      for(int i=0;i<n;++i){
         ll j = ans[i];
         if(a[i+1][j]-a[i+1][j-1] < mn){
            idx = i;
            mn = a[i+1][j]-a[i+1][j-1];
         }
      }
      ans[idx]--;
   }
   for(auto x:ans){
      cout << x << " ";
   }
   cout << endl;

}

int main(){
    int t = 1;
   //  cin >> t;
    while(t--){
        solve();
    }
    return 0;
}