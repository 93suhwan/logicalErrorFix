#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int qkpow(int a, int b) {
  int base = a, ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * base % mod;
    base = 1ll * base * base % mod;
    b >>= 1;
  }
  return ans;
}
int fac[1000005], inv[1000005];
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void init_C(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[0] = 1;
  inv[n] = qkpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 1; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int t, n, m, k, now, x[200005], y[200005], wtf[200005];
long long ans;
struct node {
  int x, y;
} a[300005];
bool cmp(node A, node B) { return A.x < B.x; }
struct BIT {
  int tree[1000005];
  void MemSet() { fill(tree + 1, tree + n + 1, 0); }
  void Add(int i, int x) {
    while (i <= 1000001) {
      tree[i] += x, i += i & -i;
    }
  }
  int Query(int i) {
    int s = 0;
    while (i > 0) {
      s += tree[i];
      i -= i & -i;
    }
    return s;
  }
} bit;
void solve(int l, int r) {
  if (l > r) return;
  int tot = ans;
  for (int j = l; j <= r; j++) {
    int Id1 = lower_bound(y + 1, y + m + 1, a[j].y) - y;
    int Id2 = lower_bound(y + 1, y + m + 1, a[j].y) - y - 1;
    if (y[Id1] == a[j].y) {
      ans += k - r;
      continue;
    }
    if (Id1 >= 1 && Id1 <= m) ans += (k - r) - bit.Query(y[Id1] - 1);
    if (Id2 >= 1 && Id2 <= m) ans += bit.Query(y[Id2]);
  }
  for (int j = l; j <= r; j++) {
    ans += wtf[a[j].y];
    wtf[a[j].y]++;
  }
  for (int j = l; j <= r; j++) wtf[a[j].y]--;
  for (int j = l; j <= r; j++) bit.Add(a[j].y, 1);
  now = l - 1;
}
signed main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &y[i]), y[i]++;
    for (int i = 1; i <= k; i++) scanf("%d %d", &a[i].x, &a[i].y), a[i].y++;
    sort(a + 1, a + k + 1, cmp);
    ans = 0;
    now = k;
    x[0] = -1;
    for (int i = n; i >= 1; i--) {
      int l = now;
      if (a[now].x == x[i]) {
        while (l - 1 >= 1 && a[l - 1].x == x[i]) l--;
        if (l >= 1 && a[l].x == x[i]) {
          for (int j = now; j >= l; j--) solve(j, j);
        }
      }
      while (l - 1 >= 1 && a[l - 1].x < x[i] && a[l - 1].x > x[i - 1]) l--;
      if (l >= 1 && a[l].x <= x[i]) solve(l, now);
    }
    for (int i = 1; i <= k; i++) bit.Add(a[i].y, -1);
    cout << 1ll * k * (k - 1) / 2 - ans << endl;
  }
  return 0;
}
