#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n, m, mds;
int mod[5], hshs[maxn][5], hsht[maxn][5], z[maxn << 1], mul[maxn][5];
string s, t;
int check(int x) {
  if (x <= 2) return x == 2;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
void Z_function(string s) {
  int n = s.size(), l = 0, r = 0;
  s = " " + s, z[1] = n;
  for (int i = 2; i <= n; i++) {
    if (i <= r)
      z[i] = min(z[i - l], r - i + 1);
    else
      z[i] = 0;
    while (i + z[i] <= n && s[i + z[i]] == s[1 + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
void calc(int al, int ar, int bl, int br) {
  if (1 <= al && al <= ar && ar <= n && 1 <= bl && bl <= br && br <= n) {
    for (int i = 1; i <= 4; i++) {
      int va = (hshs[ar][i] -
                1ll * hshs[al - 1][i] * mul[ar - al + 1][i] % mod[i] + mod[i]) %
               mod[i];
      int vb = (hshs[br][i] -
                1ll * hshs[bl - 1][i] * mul[br - bl + 1][i] % mod[i] + mod[i]) %
               mod[i];
      if ((va + vb) % mod[i] != hsht[m][i]) return;
    }
    printf("%d %d\n%d %d\n", al, ar, bl, br);
    exit(0);
  }
}
int main() {
  while (mds < 4) {
    int x = 1ll * rand() * rand() % 99900000 + 100000;
    if (check(x)) mod[++mds] = x;
  }
  cin >> s >> t, n = s.size(), m = t.size(), Z_function(t + "#" + s),
                 s = " " + s, t = " " + t;
  for (int i = 1; i <= 4; i++) mul[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 4; j++) mul[i][j] = mul[i - 1][j] * 10 % mod[j];
  for (int i = 1; i <= 4; i++) hshs[0][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 4; j++)
      hshs[i][j] = (hshs[i - 1][j] * 10 + s[i] - 48) % mod[j];
  for (int i = 1; i <= 4; i++) hsht[0][i] = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= 4; j++)
      hsht[i][j] = (hsht[i - 1][j] * 10 + t[i] - 48) % mod[j];
  for (int i = 1; i <= n; i++) {
    int len = z[m + i + 1];
    calc(i, i + (m - 1) - 1, i + (m - 1), i + (m - 1) + (m - 1) - 1);
    calc(i, i + m - 1, i + m, i + m + (m - len) - 1),
        calc(i, i + m - 1, i + m, i + m + (m - len - 1) - 1);
    calc(i - 1 - (m - len) + 1, i - 1, i, i + m - 1),
        calc(i - 1 - (m - len - 1) + 1, i - 1, i, i + m - 1);
  }
  return 0;
}
