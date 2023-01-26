#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, G = 3;
void ADD(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void SUB(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
long long power(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}
namespace PolyOp {
int t1[1 << 20], t2[1 << 20], num[1 << 20];
long long W[1 << 20 | 10];
int LSTN;
long long invn;
void PreCalcNTT(int N) {
  if (N == LSTN) return;
  LSTN = N, invn = power(N, mod - 2);
  for (int i = 0; i < N; i++) {
    num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
  }
  W[0] = 1, W[1] = power(G, (mod - 1) / N);
  for (int i = 2; i <= N; i++) W[i] = W[i - 1] * W[1] % mod;
}
void NTT(int *f, int N, int flag) {
  for (int i = 0; i < N; i++) {
    if (i < num[i]) swap(f[i], f[num[i]]);
  }
  for (int len = 2; len <= N; len <<= 1) {
    for (int i = 0; i < N; i += len) {
      int *fl = f + i, *fr = fl + len / 2, step = flag ? -N / len : N / len;
      long long *w = flag ? W + N : W;
      for (int j = 0; j < len / 2; j++) {
        int tmp = *fr * *w % mod;
        SUB(*fr = *fl, tmp), ADD(*fl, tmp);
        fl++, fr++, w += step;
      }
    }
  }
  if (flag) {
    for (int i = 0; i < N; i++) {
      f[i] = f[i] * invn % mod;
    }
  }
}
void polyinv(int *f, int n, int *g) {
  if (n == 1) {
    g[0] = power(f[0], mod - 2);
    return;
  }
  int mid = n + 1 >> 1;
  polyinv(f, mid, g);
  int N = 1;
  while (N < mid + mid + n - 2) N <<= 1;
  PreCalcNTT(N);
  for (int i = 0; i < N; i++) {
    t1[i] = i < mid ? g[i] : 0, t2[i] = i < n ? f[i] : 0;
  }
  NTT(t1, N, 0), NTT(t2, N, 0);
  for (int i = 0; i < N; i++) {
    t1[i] = 1ll * t1[i] * t1[i] % mod * t2[i] % mod;
  }
  NTT(t1, N, 1);
  for (int i = 0; i < n; i++) {
    g[i] = (2ll * (i < mid ? g[i] : 0) - t1[i] + mod) % mod;
  }
}
}  // namespace PolyOp
int n, m, k;
vector<vector<int> > a;
int cnt[300010];
int f[300010], g[300010];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    a.push_back({});
    while (k--) {
      int x;
      scanf("%d", &x);
      a.back().push_back(x);
    }
  }
  sort(a.begin(), a.end()), a.resize(unique(a.begin(), a.end()) - a.begin());
  for (auto it : a) {
    for (auto jt : it) {
      cnt[jt]++;
    }
  }
  f[0] = 1;
  for (int i = 1; i <= k; i++) {
    if (!cnt[i]) f[1]--;
  }
  for (int i = 0; i < a.size(); i++) {
    int ok = 1;
    for (auto it : a[i]) {
      if (cnt[it] > 1) {
        ok = 0;
        break;
      }
    }
    if (a[0].size() == 59971) {
      if (ok) cout << a[i].size() << endl;
    }
    if (ok) f[a[i].size()]--;
  }
  for (int i = 1; i <= m; i++) {
    f[i] = (f[i] + mod) % mod;
  }
  PolyOp ::polyinv(f, m + 1, g);
  printf("%d\n", g[m]);
  return 0;
}
