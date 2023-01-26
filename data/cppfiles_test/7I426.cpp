#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const double gold = (1 + sqrt(5)) / 2.0;
const double PI = acos(-1);
const double eps = 1e-7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long pow(long long x, long long y, long long mod) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
long long pow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return ans;
}
long long inv(long long x) { return pow(x, mod - 2); }
long long tree[4 * N];
long long a[N];
void pushup(int p) { tree[p] = gcd(tree[p * 2], tree[p * 2 + 1]); }
void build(int p, int l, int r) {
  if (l == r) {
    tree[p] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  pushup(p);
}
long long query(int p, int L, int R, int l, int r) {
  if (L <= l && r <= R) {
    return tree[p];
  }
  int mid = l + r >> 1;
  long long g;
  if (L <= mid) g = abs(gcd(g, query(p * 2, l, mid, L, R)));
  if (R > mid) g = abs(gcd(g, query(p * 2 + 1, mid + 1, r, L, R)));
  return g;
}
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", a + i);
    }
    for (int i = 1; i < n; i++) {
      a[i] = abs(a[i] - a[i + 1]);
    }
    build(1, 1, n - 1);
    int ans = 2;
    for (int l = 1, r = 2; r < n; r++) {
      while (l < r && query(1, l, r, 1, n - 1) == 1) {
        l++;
      }
      ans = max(ans, r - l + 2);
    }
    printf("%d\n", ans);
  }
}
