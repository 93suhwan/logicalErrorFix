#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
const long long int mod = 1e9 + 7;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void read(vector<T>& v) {
  for (T& i : v) cin >> i;
}
template <typename T>
void read(T&& t) {
  cin >> t;
}
template <typename T, typename... Args>
void read(T&& t, Args&&... args) {
  cin >> t;
  read(forward<Args>(args)...);
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  ll n;
  cin >> n;
  vector<vector<ll>> dp(65, vector<ll>(10, -1));
  function<ll(ll, ll)> dfs = [&](ll lvl, ll prevMekyaTha) {
    if (lvl == n) return 1ll;
    if (dp[lvl][prevMekyaTha] != -1) {
      return dp[lvl][prevMekyaTha];
    }
    ll ans = 0;
    for (ll i = 1; i <= 6; i++) {
      for (ll j = 1; j <= 6; j++) {
        if (i == prevMekyaTha || j == prevMekyaTha) continue;
        if ((i == 2 && prevMekyaTha == 1) || (i == 1 && prevMekyaTha == 2) ||
            (j == 1 && prevMekyaTha == 2) || (j == 2 && prevMekyaTha == 1))
          continue;
        if ((i == 3 && prevMekyaTha == 4) || (i == 4 && prevMekyaTha == 3) ||
            (j == 3 && prevMekyaTha == 4) || (j == 4 && prevMekyaTha == 3))
          continue;
        if ((i == 5 && prevMekyaTha == 6) || (i == 6 && prevMekyaTha == 5) ||
            (j == 5 && prevMekyaTha == 6) || (j == 6 && prevMekyaTha == 5))
          continue;
        ans = (ans + dfs(lvl + 1, i) * dfs(lvl + 1, j) % mod) % mod;
      }
    }
    return dp[lvl][prevMekyaTha] = ans;
  };
  ll ans = 0;
  for (ll i = 1; i <= 6; i++) {
    ans = ans + dfs(1, i);
    ans %= mod;
  }
  print(ans);
}
