#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = 1;
  string r = "{";
  for (const auto &x : v) {
    if (!f) r += ", ";
    f = 0;
    r += to_string(x);
  }
  return r + "}";
}
void debug_out() { cout << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
const long long MOD = 1000000007;
const int INF = (int)1e9 + 5;
long long binpow(long long b, long long p) {
  long long ans = 1;
  while (p > 0) {
    if (p & 1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    p >>= 1;
  }
  return ans;
}
long long modinv(long long x) { return binpow(x % MOD, MOD - 2); }
const int mxn = 5e5 + 5;
void solve() {
  int q, i, x, y;
  cin >> q;
  vector<pair<int, int>> queries;
  for (i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> x;
      queries.push_back({-1, x});
    } else {
      cin >> x >> y;
      queries.push_back({x, y});
    }
  }
  vector<int> ans;
  map<int, int> change;
  for (i = 1; i <= 5e5 + 5; i++) {
    change[i] = i;
  }
  for (i = q - 1; i >= 0; i--) {
    if (queries[i].first == -1) {
      ans.push_back(change[queries[i].second]);
    } else {
      change[queries[i].first] = change[queries[i].second];
    }
  }
  reverse((ans).begin(), (ans).end());
  for (auto &x : ans) {
    cout << x << " ";
  }
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1, i;
  for (i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
