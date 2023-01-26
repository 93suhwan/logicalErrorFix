#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, mum = 1e9 + 7;
int n, m;
int tobe[3], F[3][maxn], f[3][maxn], md[3] = {mum, 998244353, mum - 4},
                                     g[3][maxn];
struct node {
  int f[3];
  bool operator==(const node& A) const {
    int num = 0;
    for (int j = 0; j <= 2; j++) num += f[j] == A.f[j];
    return num == 3;
  }
};
node choose(int l, int r) {
  node Return;
  for (int j = 0; j <= 2; j++) {
    int num =
        (f[j][r] - 1LL * f[j][l - 1] * F[j][r - l + 1] % md[j] + md[j]) % md[j];
    Return.f[j] = num;
  }
  return Return;
}
node choose_t(int l, int r) {
  node Return;
  for (int j = 0; j <= 2; j++) {
    int num =
        (g[j][r] - 1LL * g[j][l - 1] * F[j][r - l + 1] % md[j] + md[j]) % md[j];
    Return.f[j] = num;
  }
  return Return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s, t;
  cin >> s >> t;
  n = s.length();
  m = t.length();
  for (int i = 0; i <= 2; i++) f[i][0] = g[i][0] = F[i][0] = 1;
  for (int i = 1; i <= max(n, m); i++)
    for (int j = 0; j <= 2; j++) F[j][i] = 1LL * F[j][i - 1] * 10 % md[j];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 2; j++)
      f[j][i] = (1LL * f[j][i - 1] * 10 % md[j] + s[i - 1] - '0') % md[j];
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= 2; j++)
      g[j][i] = (1LL * g[j][i - 1] * 10 % md[j] + t[i - 1] - '0') % md[j];
  for (auto i : t)
    for (int j = 0; j <= 2; j++)
      tobe[j] = (1LL * tobe[j] * 10 % md[j] + i - '0') % md[j];
  m--;
  for (int i = m, j = i + m; j <= n; j++, i++) {
    node gget1 = choose(i - m + 1, i), gget2 = choose(i + 1, j);
    int num = 0;
    for (int now = 0; now <= 2; now++)
      num += (gget1.f[now] + gget2.f[now]) % md[now] == tobe[now];
    if (num == 3) {
      cout << i - m + 1 << " " << i << '\n';
      cout << i + 1 << " " << j << '\n';
      return 0;
    }
  }
  m++;
  for (int i = 1, j = i + m - 1; j <= n; i++, j++) {
    int l = 0, mid, r = j - i + 1;
    while (l < r) {
      mid = l + r + 1 >> 1;
      node gget = choose(i, i + mid - 1);
      node gget2 = choose_t(1, mid);
      if (gget == gget2)
        l = mid;
      else
        r = mid - 1;
    }
    node now_big = choose(i, j);
    node have;
    for (int now = 0; now <= 2; now++)
      have.f[now] = (tobe[now] - now_big.f[now] + md[now]) % md[now];
    for (int need = max(1, j - i - l); need <= j - i - l + 1; need++) {
      if (i - need <= 0) continue;
      node gget = choose(i - need, i - 1);
      if (gget == have) {
        cout << i - need << " " << i - 1 << '\n';
        cout << i << " " << j << '\n';
        return 0;
      }
    }
    for (int need = max(1, j - i - l); need <= j - i - l + 1; need++) {
      if (j + need > n) continue;
      node gget = choose(j + 1, j + need);
      if (gget == have) {
        cout << i << " " << j << '\n';
        cout << j + 1 << " " << j + need << '\n';
        return 0;
      }
    }
  }
  return 0;
}
