#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
string to_string(char s) {
  string res = "'''";
  res[1] = s;
  return res;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = 1;
  string res = "{";
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = 0;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug() { cout << "\n"; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug(T...);
}
const long long int MOD = 1e9 + 7;
inline long long int add(long long int a, long long int b,
                         long long int p = MOD) {
  a = a + b;
  if (a >= p) a -= p;
  return a;
}
inline long long int sub(long long int a, long long int b,
                         long long int p = MOD) {
  a = a - b;
  if (a < 0) a += p;
  return a;
}
inline long long int mul(long long int a, long long int b,
                         long long int p = MOD) {
  a = (a * 1ll * b) % p;
  return a;
}
const ld pi = acos(-1), eps = 1e-9;
const ll inf = 1e18;
const long long int N = 2e5 + 5;
long long int tree[4 * N];
void point_update(long long int node, long long int beg, long long int en,
                  long long int idx, long long int val) {
  if (beg == en) {
    tree[node] += val;
    return;
  }
  long long int mid = (beg + en) / 2;
  if (beg <= idx && idx <= mid)
    point_update(2 * node, beg, mid, idx, val);
  else
    point_update(2 * node + 1, mid + 1, en, idx, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long int range_query(long long int node, long long int beg,
                          long long int en, long long int l, long long int r) {
  if (r < beg || en < l) return 0;
  if (l <= beg && en <= r) return tree[node];
  long long int mid = (beg + en) / 2;
  long long int q1 = range_query(2 * node, beg, mid, l, r);
  long long int q2 = range_query(2 * node + 1, mid + 1, en, l, r);
  return (q1 + q2);
}
void init(long long int n) {
  for (long long int i = 0; i < (4 * n + 3); ++i) tree[i] = 0;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < (n); ++i) cin >> v[i];
  map<long long int, long long int> compress;
  for (auto c : v) compress[c];
  long long int cnt = 0;
  for (auto& c : compress) c.second = ++cnt;
  init(cnt);
  long long int dp[n + 1][2];
  memset(dp, 0, sizeof(dp));
  for (long long int i = (1); i <= (n); ++i) {
    for (long long int j = 0; j < (2); ++j)
      dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]);
    long long int val = compress[v[i - 1]];
    dp[i][0] += range_query(1, 1, cnt, 1, val - 1);
    dp[i][1] += range_query(1, 1, cnt, val + 1, cnt);
    point_update(1, 1, cnt, val, 1);
  }
  long long int ans = min(dp[n][0], dp[n][1]);
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  for (long long int z = 1; z <= t; ++z) {
    solve();
    cout << "\n";
  }
  return 0;
}
