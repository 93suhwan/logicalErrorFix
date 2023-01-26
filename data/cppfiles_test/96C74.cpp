#include <bits/stdc++.h>
using namespace std;
const int N = 510, Mod = 998244353;
inline int add(int a, int b) { return a + b >= Mod ? a + b - Mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + Mod : a - b; }
int n, x, f[N][N], ans;
int Pow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % Mod;
    a = 1ll * a * a % Mod;
    b >>= 1;
  }
  return ret;
}
int ni[N], jie[N];
void getall() {
  jie[0] = ni[0] = 1;
  for (int i = 1; i < N; ++i) jie[i] = 1ll * jie[i - 1] * i % Mod;
  int tmp = Pow(jie[N - 1], Mod - 2);
  for (int i = N - 1; i >= 1; --i) ni[i] = tmp, tmp = 1ll * tmp * i % Mod;
}
int C(int a, int b) { return 1ll * jie[a] * ni[b] % Mod * ni[a - b] % Mod; }
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> x;
  int now = 0;
  getall();
  f[n][0] = 1;
  for (int i = n; i > 1; --i) {
    for (int j = 0; j < x; ++j) {
      if (!f[i][j]) continue;
      int tar = min(x, i + j - 1), Pow = 1;
      for (int k = i; k >= 0; --k)
        f[k][tar] = add(f[k][tar], 1ll * f[i][j] * C(i, k) % Mod * Pow % Mod),
        Pow = 1ll * Pow * (tar - j) % Mod;
    }
  }
  for (int i = 0; i <= x; ++i) ans = add(ans, f[0][i]);
  cout << ans << endl;
  return 0;
}
