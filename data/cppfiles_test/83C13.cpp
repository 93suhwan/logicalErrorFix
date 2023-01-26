#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 1e6 + 10, mod1 = 998244353, mod2 = 1e9 + 7;
long long n, pw[15];
int len, B, p[15];
long long rk;
vector<int> c[4][15];
int s[4][15];
inline void init_dfs1(int k, int x) {
  ++rk, c[1][k - 1].push_back((rk + mod1 - x) % mod1);
  if (k > len - B) return;
  for (int i = (0); i <= (9); i++) init_dfs1(k + 1, x * 10 + i);
}
inline void init_dfs2(int k, int x, int op) {
  if (k <= len - B || (k > len - B && op != 1))
    ++rk, c[2][k - 1].push_back((rk + mod1 - x) % mod1);
  if (k > len - B) return;
  int num = p[len - B - k + 1];
  for (int i = (0); i <= (9); i++)
    init_dfs2(k + 1, x * 10 + i, op != -1 ? op : (i == num ? -1 : i > num));
}
inline void init_dfs3(int k, int x) {
  ++rk, c[3][k - 1].push_back((rk + mod1 - x) % mod1);
  if (k == len - B) return;
  for (int i = (0); i <= (9); i++) init_dfs3(k + 1, x * 10 + i);
}
int ans;
inline int calc(int b, int k) {
  int ret = 0;
  for (int i = (0); i <= (len - B); i++) {
    if (c[k][i].empty()) continue;
    int t = (rk + 1ll * (mod1 - b) * pw[i]) % mod1;
    ret = (ret + s[k][i] + 1ll * t * ((int)(c[k][i]).size())) % mod2;
    int tmp = lower_bound((c[k][i]).begin(), (c[k][i]).end(), mod1 - t) -
              c[k][i].begin();
    ret = (ret + 1ll * (mod2 - mod1) * (((int)(c[k][i]).size()) - tmp)) % mod2;
  }
  for (int i = (0); i <= (len - B); i++) rk += ((int)(c[k][i]).size());
  return ret;
}
inline void dfs(int k, int x, int op) {
  if (k > B) {
    if (op == 0)
      ans = (ans + calc(x, 1)) % mod2;
    else if (op == 1)
      ans = (ans + calc(x, 3)) % mod2;
    else
      ans = (ans + calc(x, 2)) % mod2;
    return;
  }
  if (k > 1) ++rk, ans = (ans + (rk + mod1 - x) % mod1) % mod2;
  int num = p[len - k + 1];
  for (int i = (k == 1); i <= (9); i++)
    dfs(k + 1, x * 10 + i, op != -1 ? op : (i == num ? -1 : i > num));
}
int main() {
  n = read();
  if (n <= 9) return puts("0"), 0;
  for (long long i = n; i; i /= 10) p[++len] = i % 10;
  B = (len + 1) / 2;
  rk = 0, init_dfs1(1, 0);
  rk = 0, init_dfs2(1, 0, -1);
  rk = 0, init_dfs3(1, 0);
  for (int i = (0); i <= (len - B); i++)
    for (int j = (1); j <= (3); j++) {
      sort((c[j][i]).begin(), (c[j][i]).end());
      for (auto k : c[j][i]) s[j][i] = (s[j][i] + k) % mod2;
    }
  pw[0] = 1;
  for (int i = (1); i <= (len); i++) pw[i] = 10 * pw[i - 1];
  rk = 0, dfs(1, 0, -1), printf("%d\n", ans);
}
