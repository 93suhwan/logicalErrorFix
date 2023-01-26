#include <bits/stdc++.h>
const int N = 2e5 + 5;
using namespace std;
int n, q, a[N], op, x, y;
int L[N << 2], R[N << 2];
long long sum[N << 2];
void pushup(int p, int l, int r) {
  sum[p] = sum[p << 1] + sum[p << 1 | 1];
  int mid = (l + r) >> 1;
  int lenl = (mid - l + 1), lenr = (r - l + 1) - lenl;
  L[p] = L[p << 1], R[p] = R[p << 1 | 1];
  if (a[mid] <= a[mid + 1]) {
    sum[p] += 1LL * R[p << 1] * L[p << 1 | 1];
    if (L[p] == lenl) L[p] += L[p << 1 | 1];
    if (R[p] == lenr) R[p] += R[p << 1];
  }
}
void build(int p, int l, int r) {
  if (l == r) {
    sum[p] = 1;
    L[p] = R[p] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
  pushup(p, l, r);
}
void update(int p, int l, int r, int x, int k) {
  if (l == r) {
    a[x] = k;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) update(p << 1, l, mid, x, k);
  if (x > mid) update(p << 1 | 1, mid + 1, r, x, k);
  pushup(p, l, r);
}
long long query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) return sum[p];
  long long res = 0;
  int mid = (l + r) >> 1;
  if (x <= mid) res += query(p << 1, l, mid, x, y);
  if (y > mid) res += query(p << 1 | 1, mid + 1, r, x, y);
  if (x <= mid && y > mid) {
    if (a[mid] <= a[mid + 1]) res += 1LL * R[p << 1] * L[p << 1 | 1];
  }
  return res;
}
signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      update(1, 1, n, x, y);
    } else {
      printf("%lld\n", query(1, 1, n, x, y));
    }
  }
  return 0;
}
