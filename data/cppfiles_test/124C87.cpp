#include <bits/stdc++.h>
using namespace std;
const int maxn = 2050, mod = (int)1e9 + 7;
int T;
int n;
char s[maxn], t[maxn];
int ans;
int pre[maxn][maxn * 2], suf[maxn][maxn * 2];
char flip(char c) { return c == '?' ? '?' : (c == '1' ? '0' : '1'); }
void Mod(int &x) { x %= mod; }
void Add(int &x, int y) {
  x += y;
  Mod(x);
}
void trans_pre(int i, int j, int ss, int tt) {
  int jj = j - (ss - tt);
  if (jj > 0) Add(pre[i][j], pre[i - 1][jj]);
}
void trans_suf(int i, int j, int ss, int tt) {
  int jj = j - (ss - tt);
  if (jj > 0) Add(suf[i][j], suf[i + 1][jj]);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    scanf("%d%s%s", &n, s + 1, t + 1);
    for (int i = 2; i <= n; i += 2) {
      s[i] = flip(s[i]);
      t[i] = flip(t[i]);
    }
    for (int j = 0; j <= 2 * n; j++) pre[0][j] = 0;
    pre[0][n] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 2 * n; j++) {
        pre[i][j] = 0;
        if (s[i] == '?' && t[i] == '?') {
          trans_pre(i, j, 0, 0);
          trans_pre(i, j, 0, 1);
          trans_pre(i, j, 1, 0);
          trans_pre(i, j, 1, 1);
        } else if (s[i] == '?') {
          trans_pre(i, j, 0, t[i] - '0');
          trans_pre(i, j, 1, t[i] - '0');
        } else if (t[i] == '?') {
          trans_pre(i, j, s[i] - '0', 0);
          trans_pre(i, j, s[i] - '0', 1);
        } else
          trans_pre(i, j, s[i] - '0', t[i] - '0');
      }
    for (int j = 0; j <= 2 * n; j++) suf[n + 1][j] = 0;
    suf[n + 1][n] = 1;
    for (int i = n; i >= 1; i--)
      for (int j = 0; j <= 2 * n; j++) {
        suf[i][j] = 0;
        if (s[i] == '?' && t[i] == '?') {
          trans_suf(i, j, 0, 0);
          trans_suf(i, j, 0, 1);
          trans_suf(i, j, 1, 0);
          trans_suf(i, j, 1, 1);
        } else if (s[i] == '?') {
          trans_suf(i, j, 0, t[i] - '0');
          trans_suf(i, j, 1, t[i] - '0');
        } else if (t[i] == '?') {
          trans_suf(i, j, s[i] - '0', 0);
          trans_suf(i, j, s[i] - '0', 1);
        } else
          trans_suf(i, j, s[i] - '0', t[i] - '0');
      }
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 2 * n; j++)
        Add(ans,
            1LL * pre[i][j] * suf[i + 1][2 * n - j] % mod * abs(j - n) % mod);
    cout << ans << endl;
  }
  return 0;
}
