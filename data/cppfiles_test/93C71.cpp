#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char s) { return (string) "'" + s + "'"; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(const bitset<N> &v) {
  return v.to_string();
}
template <typename A>
string to_string(const A &v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ",";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  dbg_out(T...);
}
const long long mod = 1e9 + 7;
long long modMul(long long a, long long b) {
  return ((((a % mod) * (b % mod)) % mod) + mod) % mod;
}
long long modSub(long long a, long long b) {
  return ((((a % mod) - (b % mod)) % mod) + mod) % mod;
}
long long modAdd(long long a, long long b) {
  return ((((a % mod) + (b % mod)) % mod) + mod) % mod;
}
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, -1, 1, 1, -1};
const long long mxN = 1e7 + 10;
const long double eps = 1e-6;
const long long inf = 1e18;
void solve(int tc) {
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n - 1 << "\n";
    return;
  }
  long long last = 1;
  long long cnt = 0;
  for (int i = 0; i < 100; i++) {
    cnt++;
    long long cur = last * 2;
    if (cur >= n) {
      cout << cnt << "\n";
      return;
    }
    if (cur >= k) {
      long long rem = n - (last + min(last, k));
      long long ans = 0;
      ;
      if (rem > 0) {
        ans = rem / k;
        if (rem % k != 0) ans++;
      }
      ans += cnt;
      ;
      cout << ans << "\n";
      return;
    }
    last = cur;
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cout << setprecision(7) << fixed;
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
