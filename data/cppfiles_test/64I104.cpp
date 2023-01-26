#include <bits/stdc++.h>
using namespace std;
const long long mod[3] = {1000000007, 1000000009, 998244353};
string s, x;
int n, m;
long long Hash[3][2000500], Z[2000500], X[3], pow[3][2000500];
void zalg() {
  int len = s.size();
  Z[0] = 0;
  int l = 0;
  for (int i = (1); i <= (len - 1); i++) {
    Z[i] = 0;
    if (Z[l] + l > i) Z[i] = min(Z[i - l], Z[l] + l - i);
    while (Z[i] + i < len && s[Z[i] + i] == s[Z[i]]) Z[i]++;
    if (Z[i] + i > Z[l] + l) l = i;
  }
  Z[0] = len;
}
long long qpow(long long a, int b, int id) {
  long long ret = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) (ret *= a) %= mod[id];
    (a *= a) %= mod[id];
  }
  return ret;
}
void prework() {
  Hash[0][0] = Hash[1][0] = Hash[2][0] = s[0] - '0';
  for (int i = (1); i <= (n - 1); i++)
    for (int p = (0); p <= (2); p++)
      Hash[p][i] = (Hash[p][i - 1] * 10 + s[i] - '0') % mod[p];
  for (int i = (0); i <= (m - 1); i++)
    for (int p = (0); p <= (2); p++) X[p] = (X[p] * 10 + x[i] - '0') % mod[p];
  for (int p = (0); p <= (2); p++) {
    pow[p][0] = 1;
    for (int i = (1); i <= (n + m + 10); i++)
      pow[p][i] = pow[p][i - 1] * 10 % mod[p];
  }
}
long long val(int l, int r, int id) {
  return (Hash[id][r] + mod[id] -
          (l ? Hash[id][l - 1] : 0) * pow[id][r - l + 1] % mod[id]) %
         mod[id];
}
bool check(int a, int b, int c, int d) {
  bool flag = true;
  for (int p = (0); p <= (2); p++)
    flag &= (val(a, b, p) + val(c, d, p)) % mod[p] == X[p];
  if (flag)
    cout << a + 1 << " " << b + 1 << "\n" << c + 1 << " " << d + 1 << endl;
  return flag;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> s >> x;
  n = s.size(), m = x.size();
  prework();
  s = x + "#" + s, zalg();
  for (int i = (0); i <= (n - m); i++) {
    int len = Z[i + m + 1];
    int lft = m - len;
    if (m > 1 && i + 2 * m - 2 <= n &&
        check(i, i + m - 2, i + m - 1, i + 2 * m - 3))
      return 0;
    for (int _ = (0); _ <= (1); _++)
      if (lft > 0) {
        if (i + m + lft <= n && check(i, i + m - 1, i + m, i + m + lft - 1))
          return 0;
        if (i >= lft && check(i - lft, i - 1, i, i + m - 1)) return 0;
        lft--;
      }
  }
  return 0;
}
