#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const long long U = 998244353;
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool f) {
  if (f)
    return "True";
  else
    return "False";
}
string to_string(const char *s) { return to_string((string)s); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = false;
  string r = "{";
  for (auto x : v) {
    if (f) r += ", ";
    r += to_string(x);
    f = true;
  }
  return r += "}";
}
template <typename A>
string to_string(vector<vector<A>> v) {
  string r;
  for (auto x : v) r += "\n" + to_string(x);
  return r;
}
long long Nerr;
template <typename A>
string to_string(A *p) {
  return to_string(vector<A>(p, p + Nerr));
}
void err(istream_iterator<string>) { cerr << '\n'; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << to_string(a) << "; ";
  err(++it, args...);
}
template <typename T>
void kek(T ans) {
  cout << ans << '\n';
  exit(0);
}
struct FenwickTree {
  vector<long long> bit;
  long long n;
  FenwickTree(long long n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<long long> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  long long sum(long long r) {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
  void add(long long idx, long long delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
map<long long, long long> dp, vis;
long long n, d;
bool f = 1;
long long dfs(long long i, vector<long long> &v) {
  if (v[i] == 0) return 0;
  if (vis.find(i) != vis.end() and dp[i] != -1)
    return dp[i];
  else if (vis.find(i) != vis.end()) {
    f = 0;
    return 0;
  }
  vis[i] = 1;
  long long ans = dfs((i + d) % n, v);
  dp[i] = 1 + ans;
  return dp[i];
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    cin >> n >> d;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) dp[i] = -1;
    vis.clear();
    f = 1;
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      ans = max(ans, dfs(i, a));
    }
    if (!f)
      cout << -1 << '\n';
    else {
      cout << ans << '\n';
    }
  }
}
