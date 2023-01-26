#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, mod;
long long f[200010], sum;
struct Node {
  int l, r;
  long long sum;
} s[N << 2];
void pushup(int p) {
  s[p].sum = s[p << 1].sum + s[p << 1 | 1].sum;
  s[p].sum %= mod;
}
void build(int p, int l, int r) {
  s[p].l = l;
  s[p].r = r;
  if (l == r) {
    s[p].sum = f[l];
    return;
  }
  int mid = (l + r) / 2;
  if (l <= mid) build(p << 1, l, mid);
  if (r > mid) build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void update(int p, int l, int r, int z) {
  if (l == s[p].l && r == s[p].r) {
    s[p].sum += z;
    return;
  }
  int mid = (s[p].l + s[p].r) >> 1;
  if (l <= mid) update(p << 1, l, r, z);
  if (r > mid) update(p << 1 | 1, l, r, z);
  pushup(p);
}
long long query(int p, int l, int r) {
  if (l <= s[p].l && r >= s[p].r) {
    return s[p].sum;
  }
  int mid = (s[p].l + s[p].r) >> 1;
  long long ans = 0;
  if (l <= mid) {
    ans += query(p << 1, l, r);
    ans %= mod;
  }
  if (r > mid) {
    ans += query(p << 1 | 1, l, r);
    ans %= mod;
  }
  return ans % mod;
}
int main() {
  scanf("%d%d", &n, &mod);
  f[n] = 1;
  build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    f[i] += sum;
    update(1, i, i, sum);
    f[i] %= mod;
    for (int j = 2; j * i <= n; j++) {
      int pan = min(i * j + (j - 1), n);
      long long ans = query(1, j * i, j * i + (j - 1));
      f[i] += ans;
      f[i] %= mod;
      update(1, i, i, ans);
    }
    sum += f[i];
    sum %= mod;
  }
  printf("%lld\n", f[1]);
}
