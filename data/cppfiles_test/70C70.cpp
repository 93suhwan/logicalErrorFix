#include <bits/stdc++.h>
using namespace std;
int a[200005], s[200005], M[1005], S[25][200005];
int L[55][200005], C[105][105];
int powdv(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) ans = 1ll * ans * x % 1000000007;
    y >>= 1;
    x = 1ll * x * x % 1000000007;
  }
  return ans;
}
int niyuan(int x) { return powdv(x, 1000000007 - 2); }
int main() {
  srand(time(0) + 20090908);
  int n, m, r = rand(), T = 3, J = 50;
  cin >> n >> m;
  for (int i = 1; i <= T; i++) M[i] = rand() % J + 1;
  for (int i = 0; i <= J; i++) {
    L[i][0] = powdv(0, i);
    for (int j = 1; j <= n; j++)
      L[i][j] = (L[i][j - 1] + powdv(j, i)) % 1000000007;
  }
  for (int i = 0; i <= J; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = (s[i - 1] + (a[i] = (a[i] + r) % 1000000007)) % 1000000007;
    for (int j = 1; j <= T; j++)
      S[j][i] = (S[j][i - 1] + powdv(a[i], M[j])) % 1000000007;
  }
  while (m--) {
    int l, r, d;
    scanf("%d%d%d", &l, &r, &d);
    int x = r - l + 1, SS = (s[r] - s[l - 1]) % 1000000007;
    int sx = ((SS - 1ll * x * (x - 1) / 2 % 1000000007 * d) % 1000000007 *
                  niyuan(x) % 1000000007 +
              1000000007) %
             1000000007;
    int flag = 1;
    for (int j = 1; j <= T; j++) {
      int k = M[j], he = 0;
      for (int l = 0; l <= k; l++) {
        int SS = 1ll * C[k][l] * powdv(d, l) % 1000000007 * powdv(sx, k - l) %
                 1000000007;
        he = (he + 1ll * SS * L[l][x - 1]) % 1000000007;
      }
      if ((0ll + he - S[j][r] + S[j][l - 1]) % 1000000007) {
        flag = 0;
        break;
      }
    }
    if (flag)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
