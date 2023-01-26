#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &a) {
  T w = 1;
  a = 0;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    a = (a << 3) + (a << 1) + (ch ^ 48);
  a *= w;
}
template <typename T>
inline void ckmax(T &a, T b) {
  a = a > b ? a : b;
}
template <typename T>
inline void ckmin(T &a, T b) {
  a = a < b ? a : b;
}
const int N = 1e5 + 10;
const int Mod = 998244353;
vector<int> to[N];
int f[N], g[N];
inline int Sub(int x, int y) { return (x - y) < 0 ? (x + Mod - y) : (x - y); }
inline int Mul(int x, int y) {
  return (1ll * x * y) >= Mod ? (1ll * x * y % Mod) : (x * y);
}
int qpow(int a, int b) {
  int base = a, ans = 1;
  while (b) {
    if (b & 1) ans = Mul(ans, base);
    base = Mul(base, base);
    b >>= 1;
  }
  return ans;
}
int fl;
int dfs(int u, int fa, int k) {
  int cnt = 0;
  for (auto v : to[u]) {
    if (v == fa) continue;
    cnt += dfs(v, u, k);
  }
  if (!(cnt % k)) return 1;
  if (!((cnt + 1) % k)) return 0;
  fl = 0;
  return 0;
}
int main() {
  int cases;
  read(cases);
  while (cases--) {
    int n;
    read(n);
    memset(f, 0, sizeof f);
    for (int i = 1, u, v; i < n; ++i) {
      read(u);
      read(v);
      to[u].push_back(v);
      to[v].push_back(u);
    }
    f[1] = qpow(2, n - 1);
    for (int i = 2; i < n; ++i) {
      if (!((n - 1) % i)) {
        fl = 1;
        f[i] = dfs(1, 0, i) && fl;
      }
    }
    for (int i = n - 1; i >= 1; --i) {
      for (int j = i + i; j < n; j += i) f[i] = Sub(f[i], f[j]);
    }
    for (int i = 1; i <= n; ++i) printf("%d ", f[i]);
    puts("");
    for (int i = 1; i <= n; ++i) to[i].clear();
  }
}
