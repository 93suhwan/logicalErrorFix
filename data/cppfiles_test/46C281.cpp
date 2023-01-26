#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline bool ckmax(A& a, B b) {
  return a < b ? a = b, true : false;
}
template <typename A, typename B>
inline bool ckmin(A& a, B b) {
  return a > b ? a = b, true : false;
}
const int MOD = 1000000007;
const int inf = 1061109567;
const int64_t INF = 4557430888798830399;
const int maxn = 2e5 + 5;
int n, a[maxn];
void gogo() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int u = *max_element(a + 1, a + 1 + n);
  int res = 0, mx = -1;
  for (int i = n; i >= 1; --i) {
    if (a[i] == u) {
      cout << res << "\n";
      return;
    }
    if (a[i] > mx) {
      mx = a[i];
      ++res;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  if (fopen("main"
            ".inp",
            "r")) {
    freopen(
        "main"
        ".inp",
        "r", stdin);
    freopen(
        "main"
        ".out",
        "w", stdout);
  }
  int ntest;
  cin >> ntest;
  while (ntest--) gogo();
  return 0;
}
