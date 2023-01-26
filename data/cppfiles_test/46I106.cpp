#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define vt vector
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ub upper_bound
#define lb lower_bound


const int inf = (int)2e9, mod = (int)1e9 + 7, mx = (int)2e5 + 10;
const ll infll = (ll)7e18;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
  int n; cin >> n;
  vi a(n); for(auto &u : a)cin >> u;
  oset<int> st;
  vector<int> lft(n);
  int j = *max_element(all(a));
  int ind = -1;
  for(int i=0; i < n; i++){
      if(j == a[i])ind = i;
  }
  int res = 0;
  for(int i=n-1; i > ind; i--){
      int v = a[i]; --i; res++;
      while(i > ind && a[i] <= v)i--;
  }
  cout << res << '\n';

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

