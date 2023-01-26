#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> ans;
  vector<long long> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> dp(513, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 513; j++) {
      if (a[i] > dp[j]) {
        long long tmp = j ^ (a[i]);
        dp[tmp] = min(dp[tmp], a[i]);
      }
    }
  }
  for (int i = 0; i < 513; i++) {
    if (dp[i] != INF) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (auto &p : ans) cout << p << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
