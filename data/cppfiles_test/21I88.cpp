#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 103;
int n, m, K, mod, mem[N][N][N], c[N][N], gt[N];
int dp(int nn, int numMax, int num) {
  if (nn == 0) return num == 0;
  if (numMax <= 0) return (num == 0 ? gt[nn] : 0);
  if (nn == 1) {
    if (numMax == 1) return num == 1;
    return num == 0;
  }
  if (num * 2 > n + 1) return 0;
  if (numMax > nn) return 0;
  int &res = mem[nn][numMax][num];
  if (res != -1) return res;
  res = 0;
  for (int posMx = (1); posMx <= (nn); ++posMx) {
    int ans = 0;
    for (int numL = (0); numL <= (num - (numMax == 1)); ++numL) {
      (ans += dp(posMx - 1, numMax - 1, numL) * 1LL *
              dp(nn - posMx, numMax - 1, num - numL - (numMax == 1)) % mod) %=
          mod;
    }
    (res += c[posMx - 1][nn - 1] * 1LL * ans % mod) %= mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> K >> mod;
  for (int i = (0); i <= (n); ++i) c[0][i] = 1 % mod;
  gt[0] = 1;
  for (int i = (1); i <= (n); ++i) {
    gt[i] = gt[i - 1] * 1LL * i % mod;
    for (int j = (i); j <= (n); ++j)
      c[i][j] = (c[i - 1][j - 1] + c[i][j - 1]) % mod;
  }
  memset(mem, -1, sizeof(mem));
  cout << dp(n, m, K);
  return 0;
}
