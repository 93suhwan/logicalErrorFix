#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
long long mod = 1e9 + 7;
struct node {
  int a, i;
  int r, c;
} p[100010], pp[400];
bool cmp1(node k1, node k2) {
  if (k1.a != k2.a) return k1.a < k2.a;
  return k1.i < k2.i;
}
bool cmp2(node k1, node k2) { return k1.i < k2.i; }
bool cmp3(node k1, node k2) {
  if (k1.a != k2.a) return k1.a < k2.a;
  return k1.i > k2.i;
}
int sum[400][500 << 2];
void build(int l, int r, int k, int f) {
  if (l > r) return;
  if (l == r) {
    sum[f][k] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, k * 2, f);
  build(mid + 1, r, k * 2 + 1, f);
  sum[f][k] = sum[f][k * 2] + sum[f][k * 2 + 1];
}
void change(int l, int r, int k, int q, int f) {
  if (l > q || r < q) return;
  if (q <= l && r <= q) {
    sum[f][k]++;
    return;
  }
  int mid = (l + r) / 2;
  change(l, mid, k * 2, q, f);
  change(mid + 1, r, k * 2 + 1, q, f);
  sum[f][k] = sum[f][k * 2] + sum[f][k * 2 + 1];
}
int query(int l, int r, int k, int ql, int qr, int f) {
  if (l > qr || r < ql) return 0;
  if (ql <= l && r <= qr) {
    return sum[f][k];
  }
  int mid = (l + r) / 2;
  return query(l, mid, k * 2, ql, qr, f) +
         query(mid + 1, r, k * 2 + 1, ql, qr, f);
}
void solve() {
  int n, m, ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m * n; i++) {
    scanf("%d", &p[i].a);
    p[i].i = i;
  }
  sort(p + 1, p + 1 + m * n, cmp1);
  for (int i = 1; i <= n; i++) {
    build(1, m, 1, i);
    for (int j = 1; j <= m; j++) {
      pp[j] = p[(i - 1) * m + j];
      pp[j].r = i;
      pp[j].c = j;
    }
    sort(pp + 1, pp + 1 + m, cmp3);
    for (int j = 1; j <= m; j++) {
      p[(i - 1) * m + pp[j].c].c = j;
      p[(i - 1) * m + pp[j].c].r = i;
    }
  }
  sort(p + 1, p + 1 + m * n, cmp2);
  for (int i = 1; i <= m * n; i++) {
    ans += query(1, m, 1, 1, p[i].c - 1, p[i].r);
    change(1, m, 1, p[i].c, p[i].r);
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
