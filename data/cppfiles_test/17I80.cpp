#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using oset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
/*
i can also write
using ll = long long;
*/
using ll = long long;
#define inf INT_MAX
#define ninf INT_MIN
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define PI 3.1415926535897932384626
#define setbits(x) __builtin_popcountll(x)
#define leading_zeros(x) __builtin_clz(x)
#define trailing_zeros(x) __builtin_ctz(x)
#define make_unique(v) v.erase(unique(v.begin(), v.end()), v.end())

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

int mpow(int base,int exp);
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
vi g[N];

void solve(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
      cin >> a[i];
  }

  deque<int> dq;
  dq.push_back(a[0]);
  oset<int> ost; // ordered multiset
  ost.insert(a[0]);
  int ans = 0;
  unordered_map<int,int> mp;
  mp[a[0]]++;
  for(int i=1;i<n;i++){
      int less_than = ost.order_of_key(a[i]);
      // mp[a[i]] will remove equal elements
      int greater_than = dq.size() - less_than - mp[a[i]];
      if(less_than >= greater_than){
          dq.push_back(a[i]);
          ans += greater_than;
      }
      else{
          dq.push_front(a[i]);
          ans += less_than;
      }
      ost.insert(a[i]);
      mp[a[i]]++;
  }
    

  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
int mpow(int base,int exp){
  base %= mod;
  int result = 1;
  while(exp > 0){
    if(exp & 1)
    result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }

  return result;
}