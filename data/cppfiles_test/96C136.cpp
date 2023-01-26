#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int mo = 998244353;
long long readint() {
  long long x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
long long tree[maxn << 2], lazy[maxn << 2];
long long a[maxn];
void build(long long x, long long l, long long r) {
  if (l == r) {
    tree[x] = a[l];
    lazy[x] = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  tree[x] = tree[x << 1] + tree[x << 1 | 1];
}
void pushdown(long long x, long long l, long long r) {
  long long mid = (l + r) >> 1;
  lazy[x << 1] += lazy[x];
  tree[x << 1] += lazy[x] * (mid - l + 1);
  lazy[x << 1 | 1] += lazy[x];
  tree[x << 1 | 1] += lazy[x] * (r - mid);
  lazy[x] = 0;
}
void update(long long x, long long l, long long r, long long goal_l,
            long long goal_r, long long val) {
  if (l >= goal_l && r <= goal_r) {
    lazy[x] += val;
    tree[x] += val * (r - l + 1);
    return;
  }
  pushdown(x, l, r);
  long long mid = (l + r) >> 1;
  if (goal_l <= mid) update(x << 1, l, mid, goal_l, goal_r, val);
  if (goal_r > mid) update(x << 1 | 1, mid + 1, r, goal_l, goal_r, val);
  tree[x] = tree[x << 1] + tree[x << 1 | 1];
}
long long query(long long x, long long l, long long r, long long goal_l,
                long long goal_r) {
  if (l >= goal_l && r <= goal_r) return tree[x];
  pushdown(x, l, r);
  long long mid = (l + r) >> 1;
  long long ans = 0;
  if (goal_l <= mid) ans += query(x << 1, l, mid, goal_l, goal_r);
  if (goal_r > mid) ans += query(x << 1 | 1, mid + 1, r, goal_l, goal_r);
  tree[x] = tree[x << 1] + tree[x << 1 | 1];
  return ans;
}
long long dp[maxn][maxn];
long long C[maxn][maxn];
long long qkpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mo;
    b >>= 1;
    a = 1ll * a * a % mo;
  }
  return ans;
}
long long solve(long long n, long long k) {
  if (n == 1) return 0;
  if (k < n || dp[n][k]) {
    if (k < n) dp[n][k] = qkpow(k, n);
    return dp[n][k];
  }
  for (long long l = 0; l <= n; l++)
    dp[n][k] = (0ll + dp[n][k] +
                solve(n - l, k - n + 1) * qkpow(n - 1, l) % mo * C[n][l]) %
               mo;
  return dp[n][k];
}
signed main() {
  long long n = readint(), k = readint();
  C[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (long long j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
  }
  for (long long i = 1; i <= k; i++) dp[0][i] = 1;
  solve(n, k);
  printf("%d\n", dp[n][k]);
  return 0;
}
