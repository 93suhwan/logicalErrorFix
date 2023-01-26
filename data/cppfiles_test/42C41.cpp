#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
template <class T>
void Plus(T &x, T y) {
  x = x + y >= mod ? x + y - mod : x + y;
}
int n, m;
struct door {
  int l, r;
  bool operator<(const door &o) const { return r < o.r; }
} d[N], s[N];
struct fenwick {
  int tr[N << 1];
  void Add(int x, int w) {
    for (; x; x -= x & -x) Plus(tr[x], w);
  }
  int Query(int x) {
    int res = 0;
    for (; x <= n * 2; x += x & -x) Plus(res, tr[x]);
    return res;
  }
} T1, T2;
int dp[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> d[i].l >> d[i].r;
  cin >> m;
  for (int i = 1, x; i <= m; ++i) cin >> x, s[i] = d[x];
  sort(d + 1, d + n + 1);
  for (int i = 1; i <= n; ++i) {
    dp[i] = T1.Query(d[i].l) + 1;
    T1.Add(d[i].l, dp[i]);
  }
  sort(s + 1, s + m + 1);
  int ans = 0;
  for (int i = n, j = m; i >= 1; --i) {
    for (; j >= 1 && s[j].r >= d[i].r; --j) T2.Add(s[j].l, 1);
    if (T2.Query(d[i].l)) Plus(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
