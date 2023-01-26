#include <bits/stdc++.h>
using namespace std;
inline long long readint() {
  long long x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return f ? -x : x;
}
const int maxn = 5e5 + 5, maxm = 2e5 + 5;
int n, m;
char s[maxn], t[maxm];
int nxt[maxm], ext[maxn];
const long long mod1 = 1e9 + 7, mod2 = 998244353;
long long pw1[maxn], pw2[maxn], hs1[maxn], hs2[maxn], x1 = 0, x2 = 0;
long long hash1(int l, int r) {
  return (hs1[r] - hs1[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
}
long long hash2(int l, int r) {
  return (hs2[r] - hs2[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
}
void check(int l1, int r1, int l2, int r2) {
  if ((hash1(l1, r1) + hash1(l2, r2)) % mod1 == x1 &&
      (hash2(l1, r1) + hash2(l2, r2)) % mod2 == x2) {
    printf("%d %d\n%d %d\n", l1, r1, l2, r2);
    exit(0);
  }
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  int l = 0, r = 0;
  nxt[1] = m;
  for (int i = 2; i <= m; i++) {
    if (i <= r) nxt[i] = min(nxt[i - l + 1], r - i + 1);
    while (i + nxt[i] <= m && t[i + nxt[i]] == t[nxt[i] + 1]) nxt[i]++;
    if (i + nxt[i] - 1 > r) {
      l = i;
      r = i + nxt[i] - 1;
    }
  }
  l = r = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= r) ext[i] = min(nxt[i - l + 1], r - i + 1);
    while (i + ext[i] <= n && ext[i] < m && s[i + ext[i]] == t[ext[i] + 1])
      ext[i]++;
    if (i + ext[i] - 1 > r) {
      l = i;
      r = i + ext[i] - 1;
    }
  }
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw1[i] = pw1[i - 1] * 10 % mod1;
    pw2[i] = pw2[i - 1] * 10 % mod2;
  }
  for (int i = 1; i <= n; i++) {
    hs1[i] = (hs1[i - 1] * 10 % mod1 + s[i] - '0') % mod1;
    hs2[i] = (hs2[i - 1] * 10 % mod2 + s[i] - '0') % mod2;
  }
  for (int i = 1; i <= m; i++) {
    x1 = (x1 * 10 % mod1 + t[i] - '0') % mod1;
    x2 = (x2 * 10 % mod2 + t[i] - '0') % mod2;
  }
  if (m > 1)
    for (int i = 1; i + m * 2 - 3 <= n; i++)
      check(i, i + m - 2, i + m - 1, i + m * 2 - 3);
  for (int i = 1; i + m - 1 <= n; i++) {
    if (m > ext[i] && i + m * 2 - ext[i] - 1 <= n)
      check(i, i + m - 1, i + m, i + m * 2 - ext[i] - 1);
    if (m > ext[i] + 1 && i + m * 2 - ext[i] - 2 <= n)
      check(i, i + m - 1, i + m, i + m * 2 - ext[i] - 2);
    if (m > ext[i] && i > m - ext[i])
      check(i - m + ext[i], i - 1, i, i + m - 1);
    if (m > ext[i] + 1 && i > m - ext[i] - 1)
      check(i - m + ext[i] + 1, i - 1, i, i + m - 1);
  }
  return 0;
}
