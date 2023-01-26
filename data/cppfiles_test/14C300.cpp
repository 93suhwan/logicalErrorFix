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
  cerr << " " << H;
  dbg_out(T...);
}
constexpr int N = 2007;
int a[N], dp[N][N];
int n, k;
inline int well_positioned(int i, int move) { return i - move == a[i]; }
int solve() {
  dp[1][0] = well_positioned(1, 0);
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      dp[i][j] = dp[i - 1][j] + well_positioned(i, j);
      dp[i][j] = max(j > 0 ? dp[i - 1][j - 1] : 0, dp[i][j]);
      ;
    }
  }
  for (int i = 0; i < n; i++) {
    if (dp[n][i] >= k) return i;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    cout << solve() << '\n';
  }
  return 0;
}
