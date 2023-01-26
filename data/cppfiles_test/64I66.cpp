#include <bits/stdc++.h>
using namespace std;
const long long mod[2] = {1000000007, 1000000009};
string s, x;
int n, m;
long long Hash[2][500500], Z[500500], X[2];
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
  Hash[0][0] = Hash[1][0] = s[0] - '0';
  for (int i = (1); i <= (n - 1); i++)
    for (int p = (0); p <= (1); p++)
      Hash[p][i] = (Hash[p][i - 1] * 10 + s[i] - '0') % mod[p];
  for (int i = (0); i <= (m - 1); i++)
    for (int p = (0); p <= (1); p++) X[p] = (X[p] * 10 + x[i] - '0') % mod[p];
}
long long val(int l, int r, int id) {
  return (Hash[id][r] + mod[id] -
          (l ? Hash[id][l - 1] : 0) * qpow(10, r - l + 1, id) % mod[id]) %
         mod[id];
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
    for (int _ = (0); _ <= (1); _++)
      if (lft > 0) {
        if (i + m + lft <= n) {
          bool flag = true;
          for (int p = (0); p <= (1); p++)
            flag &= (val(i, i + m - 1, p) + val(i + m, i + m + lft - 1, p)) %
                        mod[p] ==
                    X[p];
          if (flag) {
            cout << i + 1 << " " << i + m << "\n"
                 << i + m + 1 << " " << i + m + lft << endl;
            return 0;
          }
        }
        if (i >= lft) {
          bool flag = true;
          for (int p = (0); p <= (1); p++)
            flag &= (val(i - lft, i - 1, p) + val(i, i + m - 1, p)) % mod[p] ==
                    X[p];
          if (flag) {
            cout << i - lft + 1 << " " << i << "\n"
                 << i + 1 << " " << i + m << endl;
            return 0;
          }
        }
        lft--;
      }
  }
  return 0;
}
