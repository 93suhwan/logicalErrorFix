#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int s = 0;
  int x = 1;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
const int mod = 998244353;
const int N = 1e5 + 5;
int T, n, x, y, f[N], ans[N];
vector<int> v[N];
int ksm(int x, int k) {
  int base = 1;
  while (k) {
    if (k & 1) base = 1ll * base * x % mod;
    k >>= 1;
    x = 1ll * x * x % mod;
  }
  return base;
}
void dfs(int u, int fa, int p) {
  int siz = 0;
  for (int i = 0; i < v[u].size(); i++) {
    if (v[u][i] == fa) continue;
    dfs(v[u][i], u, p);
    siz++;
  }
  if (!siz) {
    f[fa]++;
  } else {
    if (fa) {
      if (f[u] % p == 0)
        f[fa]++;
      else
        f[u]++;
    }
  }
}
int main() {
  T = read();
  while (T--) {
    n = read();
    for (int i = 1; i < n; i++) {
      x = read();
      y = read();
      v[x].push_back(y);
      v[y].push_back(x);
    }
    int tmp = ksm(2, n - 1);
    int pre = 0;
    for (int i = 2; i <= n; i++) {
      if ((n - 1) % i == 0) {
        memset(f, 0, 4 * n);
        dfs(1, 0, i);
        int minn = 1e9;
        bool flag = 0;
        for (int k = 1; k <= n; k++) {
          minn = min(minn, f[k]);
          if (f[k] % i) flag = 1;
        }
        if (!flag) ans[i] = 1, pre++;
      }
    }
    cout << (tmp - pre + mod) % mod << " ";
    for (int i = 2; i <= n; i++) {
      cout << ans[i] << " ";
    }
    memset(ans, 0, 4 * n);
    for (int i = 1; i <= n; i++) v[i].clear();
    puts("");
  }
  return 0;
}
