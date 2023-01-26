#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma target optimize("avx2,bmi,bmi2,lzcnt,popcnt")
template <typename... T>
void dbg(const char *s, T... args) {
  int cnt = sizeof...(T);
  cerr << "\e[1;32m(" << s << ") = (";
  ((cerr << args << (--cnt ? ", " : ")\e[0m\n")), ...);
}
template <typename T>
void org(const char *s, T L, T R) {
  cerr << "\e[1;32m[ " << s << " ] = [ ";
  while (L != R || (cerr << " ]\e[0m\n", 0))
    cerr << (*L) << (++L != R ? ", " : "");
}
const int maxn = 1e5 + 5;
struct BIT {
  int a[maxn] = {};
  int n;
  inline int lowbit(int x) { return x & -x; }
  void init(int _n) {
    n = _n;
    fill(a, a + n + 1, 0);
  }
  void add(int p, int x) {
    for (int i = p; i <= n; i += lowbit(i)) a[i] = max(a[i], x);
  }
  int que(int p) {
    int ret = 0;
    for (int i = p; i > 0; i -= lowbit(i)) ret = max(ret, a[i]);
    return ret;
  }
} bit;
pair<int, int> pa[maxn];
int mi[maxn], ma[maxn], dp[maxn];
bool ans[maxn];
void solve() {
  map<int, int> idx;
  int n;
  cin >> n;
  fill(ans, ans + 2 + n, 0);
  fill(mi, mi + 2, 0);
  fill(ma, ma + 2, 0);
  for (int i = 1; i <= n; i++) cin >> pa[i].first;
  for (int i = 1; i <= n; i++) {
    cin >> pa[i].second;
    idx[pa[i].second] = i;
  }
  sort(pa + 1, pa + 1 + n);
  for (int i = 1; i <= n; i++) ma[i] = max(ma[i - 1], pa[i].second);
  mi[n + 1] = 0x3f3f3f3f;
  for (int i = n; i; i--) mi[i] = min(mi[i + 1], pa[i].second);
  int low = n;
  ans[n] = 1;
  for (int i = n - 1; i; i--) {
    int p = lower_bound(mi + i + 1, mi + 1 + n, ma[i]) - mi;
    p--;
    if (p >= low)
      low = i, ans[idx[pa[i].second]] = 1;
    else
      break;
  }
  for (int i = 1; i <= n; i++) cout << ans[i];
  cout << '\n';
}
signed main() {
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
