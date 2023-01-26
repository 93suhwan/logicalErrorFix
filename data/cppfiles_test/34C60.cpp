#include <bits/stdc++.h>
using namespace std;
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
template <typename T>
istream &operator>>(istream &stream, vector<T> &v) {
  for (T &x : v) stream >> x;
  return stream;
}
const long long inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  const long long mxn = 5e3 + 1;
  vector<vector<long long>> ind(mxn);
  const long long max_xor = 8192;
  vector<long long> dp(max_xor, inf);
  for (long long i = 0; i < n; i++) ind[a[i]].push_back(i);
  for (long long i = 0; i < mxn; i++) {
    for (long long j = 0; j < max_xor; j++) {
      auto it = lower_bound(ind[i].begin(), ind[i].end(), dp[j]);
      if (it == ind[i].end()) continue;
      dp[j ^ i] = min(dp[j ^ i], *it);
    }
    if (ind[i].size()) dp[i] = min(dp[i], ind[i].front());
  }
  dp[0] = 0;
  vector<long long> ans;
  for (long long i = 0; i < max_xor; i++)
    if ((dp[i] < inf)) ans.push_back(i);
  cout << ans.size() << "\n";
  for (long long i : ans) cout << i << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
