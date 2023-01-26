#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5, mum = 1e9 + 7;
int n, m;
int tobe[2], F[2][maxn], f[2][maxn], md[2] = {mum, 998244353}, g[2][maxn];
pair<int, int> choose(int l, int r) {
  int gget[2] = {0};
  for (int j = 0; j <= 1; j++) {
    int num =
        (f[j][r] - 1LL * f[j][l - 1] * F[j][r - l + 1] % md[j] + md[j]) % md[j];
    gget[j] = num;
  }
  return {gget[0], gget[1]};
}
pair<int, int> choose_t(int l, int r) {
  int gget[2] = {0};
  for (int j = 0; j <= 1; j++) {
    int num =
        (g[j][r] - 1LL * g[j][l - 1] * F[j][r - l + 1] % md[j] + md[j]) % md[j];
    gget[j] = num;
  }
  return {gget[0], gget[1]};
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s, t;
  cin >> s >> t;
  n = s.length();
  m = t.length();
  f[0][0] = f[1][0] = 1;
  g[0][0] = g[1][0] = 1;
  F[0][0] = F[1][0] = 1;
  for (int i = 1; i <= max(n, m); i++)
    for (int j = 0; j <= 1; j++) F[j][i] = 1LL * F[j][i - 1] * 10 % md[j];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 1; j++)
      f[j][i] = (1LL * f[j][i - 1] * 10 % md[j] + s[i - 1] - '0') % md[j];
  for (int i = 1; i <= m; i++)
    for (int j = 0; j <= 1; j++)
      g[j][i] = (1LL * g[j][i - 1] * 10 % md[j] + t[i - 1] - '0') % md[j];
  for (auto i : t)
    for (int j = 0; j <= 1; j++)
      tobe[j] = (1LL * tobe[j] * 10 % md[j] + i - '0') % md[j];
  m--;
  for (int i = m, j = i + m; j <= n; j++, i++) {
    pair<int, int> gget1 = choose(i - m + 1, i), gget2 = choose(i + 1, j);
    if ((gget1.first + gget2.first) % md[0] == tobe[0] &&
        (gget1.second + gget2.second) % md[1] == tobe[1]) {
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
      pair<int, int> gget = choose(i, i + mid - 1);
      pair<int, int> gget2 = choose_t(1, mid);
      if (gget == gget2)
        l = mid;
      else
        r = mid - 1;
    }
    pair<int, int> now_big = choose(i, j);
    int Now[2] = {now_big.first, now_big.second};
    int have[2];
    for (int now = 0; now <= 1; now++)
      have[now] = (tobe[now] - Now[now] + md[now]) % md[now];
    pair<int, int> Have = {have[0], have[1]};
    for (int need = max(1, j - i - l); need <= j - i - l + 1; need++) {
      if (i - need <= 0) continue;
      pair<int, int> gget = choose(i - need, i - 1);
      if (gget == Have) {
        cout << i - need << " " << i - 1 << '\n';
        cout << i << " " << j << '\n';
        return 0;
      }
    }
    for (int need = max(1, j - i - l); need <= j - i - l + 1; need++) {
      if (j + need > n) continue;
      pair<int, int> gget = choose(j + 1, j + need);
      if (gget == Have) {
        cout << i << " " << j << '\n';
        cout << j + 1 << " " << j + need << '\n';
        return 0;
      }
    }
  }
  return 0;
}
