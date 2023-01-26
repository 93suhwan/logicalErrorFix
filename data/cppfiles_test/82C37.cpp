#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 3e5 + 10;
int n, q, k, a[N], b[N], top, stk[N], r[N];
long long ans[N];
vector<vector<pair<int, int>>> Q[N];
int lg[N], mn[N][22];
inline int Query(int l, int r) {
  int tmp = lg[r - l + 1];
  return min(mn[l][tmp], mn[r - (1 << tmp) + 1][tmp]);
}
long long v[N << 2], tag[N << 2];
inline void Build(int u, int l, int r) {
  tag[u] = -1;
  if (l == r) return;
  int mid = l + r >> 1;
  Build(u << 1, l, mid), Build(u << 1 ^ 1, mid + 1, r);
}
inline void upd(int u, int l, int r, int x) {
  tag[u] = x, v[u] = 1ll * (r - l + 1) * x;
}
inline void push_down(int u, int l, int r, int mid) {
  if (tag[u] != -1)
    upd(u << 1, l, mid, tag[u]), upd(u << 1 ^ 1, mid + 1, r, tag[u]),
        tag[u] = -1;
}
inline void update(int u, int l, int r, int ql, int qr, int x) {
  if (ql > qr) return;
  if (l >= ql && r <= qr) return upd(u, l, r, x), void(0);
  int mid = l + r >> 1;
  push_down(u, l, r, mid);
  if (ql <= mid) update(u << 1, l, mid, ql, qr, x);
  if (qr > mid) update(u << 1 ^ 1, mid + 1, r, ql, qr, x);
  v[u] = v[u << 1] + v[u << 1 ^ 1];
}
inline long long Query(int u, int l, int r, int ql, int qr) {
  if (ql > qr) return 0;
  if (l >= ql && r <= qr) return v[u];
  int mid = l + r >> 1;
  push_down(u, l, r, mid);
  if (qr <= mid) return Query(u << 1, l, mid, ql, qr);
  if (ql > mid) return Query(u << 1 ^ 1, mid + 1, r, ql, qr);
  return Query(u << 1, l, mid, ql, qr) + Query(u << 1 ^ 1, mid + 1, r, ql, qr);
}
int main() {
  n = read(), q = read(), k = read();
  for (int i = (1); i <= (n); i++) a[i] = read();
  for (int i = (1); i <= (n); i++) mn[i][0] = a[i], lg[i] = log2(i);
  for (int j = (1); j <= (lg[n]); j++)
    for (int i = (1); i <= (n - (1 << j) + 1); i++)
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
  for (int i = (1); i <= (n); i++) b[i] = Query(i, min(i + k, n));
  for (int i = (0); i <= (k); i++) Q[i].resize(n / k + 2);
  for (int i = (1); i <= (q); i++) {
    int l = read(), r = read();
    if (r - l + 1 <= k) {
      ans[i] = a[l];
      continue;
    }
    ans[i] = a[l];
    if ((r - l + 1) % k) {
      int len = (r - l + 1) / k * k;
      r = l + len;
      Q[l % k][l / k].emplace_back(r / k - 1, i);
    } else
      Q[l % k][l / k].emplace_back(l / k + (r - l + 1) / k - 2, i);
  }
  for (int i = (1); i <= (n); i++) r[i % k] = i;
  Build(1, 0, n);
  for (int i = (0); i < (k); i++) {
    stk[top = 0] = (r[i] / k + 1) * k;
    for (int j = r[i]; j >= 1; j -= k) {
      int p = j / k;
      while (top && b[j] < b[stk[top]]) --top;
      update(1, 0, n, j / k, stk[top] / k - 1, b[j]);
      stk[++top] = j;
      for (auto t : Q[i][p]) ans[t.second] += Query(1, 0, n, j / k, t.first);
    }
    update(1, 0, n, 0, n, 0);
  }
  for (int i = (1); i <= (q); i++) printf("%lld\n", ans[i]);
}
