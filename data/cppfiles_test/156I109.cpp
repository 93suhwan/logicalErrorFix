#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long long int MOD = 1e9 + 7;
const long long int INF = 1e18;
const long long int maxn = 1e6 + 4;
long long int binpow(long long int b, long long int n, long long int mod) {
  long long int res = 1;
  while (n) {
    if (n & 1) res = res * b % mod;
    n /= 2;
    b = b * b % mod;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  long long int k;
  cin >> k;
  vector<long long int> v(n);
  long long int sum = 0LL;
  for (long long int i = 0; i < n; ++i) cin >> v[i], sum += v[i];
  sort((v).begin(), (v).end());
  if (sum <= k) {
    cout << 0 << "\n";
    return;
  }
  long long int mn = v[0] - ((sum - k) / n);
  long long int tempSum = sum - v[0] + mn;
  long long int ans = abs(v[0] - mn);
  for (int i = n - 1; i > 0; i--) {
    if (tempSum <= k) break;
    tempSum = tempSum - v[i] + mn;
    ans++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
