#include <bits/stdc++.h>
using namespace std;
int qpow(int a, int b, const int mod) {
  int res = 1;
  while (b) {
    if (b & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return res;
}
const int mod[5] = {1000000007, 1000000009, 998244353, 19260817, 192600817};
int n, m, hs[500015][5], ht[500015][5], pd[500015][5], ipd[500015][5];
char s[500015], t[500015];
int get(int l, int r, int p) {
  int val = hs[r][p] +
            (mod[p] - ((long long)hs[l - 1][p] * pd[r - l + 1][p] % mod[p]));
  val %= mod[p];
  return val;
}
void check(int l1, int r1, int l2, int r2) {
  if (l1 <= 0 || r2 > n) return;
  bool eq = 1;
  for (int p = (0); p <= (4); p++) {
    int v1 = get(l1, r1, p);
    int v2 = get(l2, r2, p);
    int val = (v1 + v2) % mod[p];
    eq &= val == ht[m][p];
  }
  if (eq) {
    printf("%d %d\n%d %d\n", l1, r1, l2, r2);
    exit(0);
  }
}
int getlen(int x, int y) {
  if (y - x + 1 < m) {
    int zero = 0;
    if (t[1] == '1' && t[2] < s[x]) zero++;
    return m - zero;
  }
  int l = x, r = y, ans = x - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    bool eq = 1;
    for (int p = (0); p <= (4); p++) {
      int v1 = get(l, mid, p);
      int v2 = ht[mid - l + 1][p];
      eq &= v1 == v2;
    }
    if (eq)
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  if (ans == y) return 0;
  int zero = ans - x + 1;
  int pos = ans + 1, ppos = ans + 2;
  if (pos <= y) {
    if (s[pos] > t[pos - x + 1]) return -1;
    if (t[pos] - s[pos] == 1 && ppos <= y && t[ppos] - s[pos] < 0) zero++;
  }
  return m - zero;
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int p = (0); p <= (4); p++)
    ipd[0][p] = pd[0][p] = 1, ipd[1][p] = qpow(10, mod[p] - 2, mod[p]);
  for (int i = (2); i <= (max(n, m)); i++)
    for (int p = (0); p <= (4); p++)
      ipd[i][p] = ((long long)ipd[i - 1][p] * ipd[i][1]) % mod[p];
  for (int i = (1); i <= (max(n, m)); i++)
    for (int p = (0); p <= (4); p++)
      pd[i][p] = (long long)pd[i - 1][p] * 10 % mod[p];
  for (int i = (1); i <= (n); i++)
    for (int p = (0); p <= (4); p++)
      hs[i][p] = ((long long)hs[i - 1][p] * 10 + (s[i] - '0')) % mod[p];
  for (int i = (1); i <= (m); i++)
    for (int p = (0); p <= (4); p++)
      ht[i][p] = ((long long)ht[i - 1][p] * 10 + (t[i] - '0')) % mod[p];
  for (int p = (-1); p <= (0); p++)
    for (int i = (1); i <= (n); i++) {
      int len = m + p;
      if (len == 0) break;
      if (i + len - 1 > n) break;
      int mlen = getlen(i, i + len - 1);
      if (mlen <= 0) continue;
      check(i - mlen, i - 1, i, i + len - 1);
      check(i, i + len - 1, i + len, i + len + mlen - 1);
    }
  return 0;
}
