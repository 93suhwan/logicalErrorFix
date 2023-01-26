#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const long long mod = 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
template <typename T>
inline void read(T &a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
int gcd(int a, int b) { return (b > 0) ? gcd(b, a % b) : a; }
long long a[N], b[N], c[N];
int n, q;
struct Node {
  int l, r;
  long long mi, mx;
} tr[N];
void build(int u, int l, int r) {
  tr[u] = {l, r, 0, 0};
  if (l == r) {
    tr[u].mi = tr[u].mx = c[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
  tr[u].mi = max(tr[u << 1].mi, tr[u << 1 | 1].mi);
}
long long query_max(int u, int l, int r) {
  if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
  long long res = 0;
  int mid = (tr[u].l + tr[u].r) >> 1;
  if (l <= mid) res = query_max(u << 1, l, r);
  if (r > mid) res = max(res, query_max(u << 1 | 1, l, r));
  return res;
}
long long query_min(int u, int l, int r) {
  if (tr[u].l >= l && tr[u].r <= r) return tr[u].mi;
  long long res = INF;
  int mid = (tr[u].l + tr[u].r) >> 1;
  if (l <= mid) res = query_max(u << 1, l, r);
  if (r > mid) res = min(res, query_max(u << 1 | 1, l, r));
  return res;
}
int main() {
  read(n), read(q);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]), c[i] = b[i] - a[i];
  for (int i = 1; i <= n; i++) c[i] += c[i - 1];
  build(1, 1, n);
  while (q--) {
    int l, r;
    read(l), read(r);
    if (c[r] - c[l - 1] != 0 || query_min(1, l, r) - c[l - 1] < 0) {
      printf("%d\n", -1);
      ;
      continue;
    }
    printf("%lld\n", query_max(1, l, r) - c[l - 1]);
    ;
  }
  return 0;
}
