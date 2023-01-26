#include <bits/stdc++.h>
using namespace std;
void in() {}
template <typename T, typename... otr_T>
void in(T &t, otr_T &...otr) {
  cin >> t;
  in(otr...);
}
void out(int a, bool ln) { printf("%d%c", a, " \n"[ln]); }
void out(long long a, bool ln) { printf("%lld%c", a, " \n"[ln]); }
void out(double a, int digit, bool ln) {
  printf("%.*f%c", digit, a, " \n"[ln]);
}
const int maxn = 5e5 + 5;
const int maxm = 2e6 + 5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const long long mod = 998244353;
int n;
long long num[23][26], f[1 << 23][2];
int main() {
  in(n);
  for (int i = 0; i < n; ++i) {
    string s;
    in(s);
    for (int j = 0; j < s.size(); ++j) {
      num[i][s[j] - 'a']++;
    }
  }
  for (int i = 1; i < 1 << n; ++i) {
    int now = 0;
    vector<int> tmp(26, inf);
    for (int j = 0; j < n; ++j) {
      if (!((i >> j) & 1)) continue;
      now++;
      for (int k = 0; k < 26; ++k) {
        tmp[k] = min(tmp[k], (int)num[j][k]);
      }
    }
    long long sum = 1;
    for (int j = 0; j < 26; ++j) {
      sum = (sum * (tmp[j] + 1)) % mod;
    }
    if (now & 1)
      f[i][1] = sum;
    else
      f[i][0] = sum;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < 1 << n; ++j) {
      if (!(j & (1 << i))) continue;
      f[j][0] = (f[j][0] + f[j - (1 << i)][0]) % mod;
      f[j][1] = (f[j][1] + f[j - (1 << i)][1]) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i < 1 << n; ++i) {
    long long now = 0, sum = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        now++;
        sum += j + 1;
      }
    }
    long long tmp = (f[i][1] - f[i][0] + mod) % mod;
    ans ^= now * sum * tmp;
  }
  out(ans, 1);
}
