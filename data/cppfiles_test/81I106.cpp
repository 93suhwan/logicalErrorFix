#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int n, d, dp[500005], cnt, ans;
int M[5000005], A[5000005], L, R, _;
void upd(int k, int l, int r) {
  if (l >= L && r <= R) {
    ++A[k];
    ++M[k];
    return;
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc | 1;
  if (A[k]) {
    A[lc] += A[k], A[rc] += A[k], M[lc] += A[k], M[rc] += A[k];
    A[k] = 0;
  }
  if (L <= m) upd(lc, l, m);
  if (R > m) upd(rc, m + 1, r);
  M[k] = max(M[lc], M[rc]);
}
void upd2(int k, int l, int r) {
  if (l == r) {
    A[k] = 0;
    M[k] = max(M[k], R);
    return;
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc | 1;
  if (A[k]) {
    A[lc] += A[k], A[rc] += A[k], M[lc] += A[k], M[rc] += A[k];
    A[k] = 0;
  }
  if (L <= m)
    upd2(lc, l, m);
  else
    upd2(rc, m + 1, r);
  M[k] = max(M[lc], M[rc]);
}
int get(int k, int l, int r) {
  if (l >= L && r <= R) {
    return M[k];
  }
  int m = (l + r) >> 1, lc = k << 1, rc = lc | 1;
  if (A[k]) {
    A[lc] += A[k], A[rc] += A[k], M[lc] += A[k], M[rc] += A[k];
    A[k] = 0;
  }
  int ret = 0;
  if (L <= m) ret = max(ret, get(lc, l, m));
  if (R > m) ret = max(ret, get(rc, m + 1, r));
  M[k] = max(M[lc], M[rc]);
  return ret;
}
pair<int, pair<int, int> > p[500005];
map<int, int> m;
int q[1000005];
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &p[i].second.second, &p[i].second.first),
        p[i].second.first = max(p[i].second.first, d),
        p[i].first = min(p[i].second.first, p[i].second.second);
  for (int i = 1; i <= n; ++i)
    q[i] = p[i].second.first, q[n + i] = p[i].second.second;
  sort(q + 1, q + n * 2 + 1);
  q[0] = -1;
  cnt = 0;
  for (int i = 1; i <= n * 2; ++i)
    if (q[i] != q[i - 1]) m[q[i]] = ++cnt;
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    if (p[i].second.second < d) continue;
    L = 1, R = m[p[i].second.second];
    dp[i] = get(1, 1, 1048576) + 1;
    if (p[i].second.first <= p[i].second.second) {
      L = m[p[i].second.first], R = m[p[i].second.second];
      upd(1, 1, 1048576);
    }
    L = m[p[i].second.first], R = dp[i];
    upd2(1, 1, 1048576);
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
