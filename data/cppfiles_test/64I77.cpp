#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 100;
long long prime[M];
int n, m, z[N * 2];
void Z(string s) {
  int len = s.size(), l = 0, r = 0;
  z[0] = len;
  for (int i = 1; i < len; i++) {
    if (l + r > i) z[i] = min(z[i - l], l + r - i);
    while (i + z[i] < len && s[z[i]] == s[i + z[i]]) z[i]++;
    if (z[i] + i > l + r) l = i, r = z[i];
  }
  return;
}
string st;
long long pw;
char s[N], t[N];
struct H {
  long long mod, h[N], p[N];
  long long val;
  void init() {
    p[0] = 1;
    for (int i = 1; i <= 5e5; i++) p[i] = p[i - 1] * pw % mod;
    for (int i = 0; i < n; i++) {
      if (i) h[i] = h[i - 1] * pw % mod;
      h[i] = h[i] + s[i] - '0';
      h[i] %= mod;
    }
    for (int i = 0; i < m; i++) val = (val * pw % mod + t[i] - '0') % mod;
    return;
  }
  long long gh(int l, int r) {
    return (h[r] - (l == 0 ? 0 : h[l - 1]) * p[r - l + 1] % mod + mod) % mod;
  }
} f[2];
bool judge(int l, int r, int L, int R) {
  if (l >= 0 && L >= 0 && r < n && R < n && l <= r && L <= R) {
    for (int i = 0; i < 1; i++) {
      long long v = f[i].gh(l, r);
      long long V = f[i].gh(L, R);
      v = (v + V) % f[i].mod;
      if (v != f[i].val) return false;
    }
    return true;
  } else
    return false;
}
int main() {
  pw = 10;
  prime[0] = 1000000007;
  prime[1] = 1000000009;
  prime[2] = 1000000021;
  prime[3] = 1004535809;
  prime[4] = 1000010801;
  scanf("%s", &s);
  scanf("%s", &t);
  n = strlen(s), m = strlen(t);
  for (int i = 0; i < m; i++) st += t[i];
  for (int i = 0; i < n; i++) st += s[i];
  Z(st);
  f[0].mod = prime[3];
  f[0].init();
  for (int i = 0; i < n; i++) {
    int j = z[i + m];
    if (j < m && judge(i, i + m - 1, i + m, i + m * 2 - j - 1)) {
      printf("%d %d\n%d %d\n", i + 1, i + m, i + m + 1, i + m * 2 - j);
      return 0;
    }
    if (j < m && i - (m - j) >= 0 && judge(i - (m - j), i - 1, i, i + m - 1)) {
      printf("%d %d\n%d %d\n", i - (m - j) + 1, i, i + 1, i + m);
      return 0;
    }
    if (j < m) {
      j++;
      if (i + m * 2 - j - 1 < n &&
          judge(i, i + m - 1, i + m, i + m * 2 - j - 1)) {
        printf("%d %d\n%d %d\n", i + 1, i + m, i + m + 1, i + m * 2 - j);
        return 0;
      }
      if (i - (m - j) >= 0 && i - (m - j) >= 0 &&
          judge(i - (m - j), i - 1, i, i + m - 1)) {
        printf("%d %d\n%d %d\n", i - (m - j) + 1, i, i + 1, i + m);
        return 0;
      }
    }
    if (judge(i, i + m - 1, i + m, i + m * 2 - 2)) {
      printf("%d %d\n%d %d\n", i + 1, i + m, i + m + 1, i + m * 2 - 2);
      return 0;
    }
    if (i - m + 1 >= 0 && judge(i - m + 1, i - 1, i, i + m - 1)) {
      printf("%d %d\n%d %d\n", i - m + 2, i, i + 1, i + m);
      return 0;
    }
    if (i - m + 1 >= 0 && judge(i - m + 1, i - 1, i, i + m - 2)) {
      printf("%d %d\n%d %d\n", i - m + 2, i, i + 1, i + m - 1);
      return 0;
    }
  }
  return 0;
}
