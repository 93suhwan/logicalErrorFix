#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
long long int modpow(long long int x, long long int e) {
  if (e == 1)
    return x;
  else if (e == 0)
    return 1;
  long long int res = modpow(x, e / 2);
  res = res * res;
  res %= mod;
  if (e % 2 == 1) {
    res *= x;
    res %= mod;
  }
  return res;
}
long long int mulinv[100005], fac[100005], facinv[100005];
long long int choose(long long int x, long long int k) {
  long long int a = x - k;
  long long int res = fac[x];
  res *= facinv[a];
  res %= mod;
  res *= facinv[k];
  res %= mod;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, m, t, a, b, c, h, d, x, y, z, i, j, k,
      ans = 0, ans2 = 0, cur = 0, cur2 = 0, sum = 0, sum2 = 0, maxn;
  string str = "", str2, str3;
  cin >> n;
  for (i = 1; i <= n; i++) mulinv[i] = modpow(i, mod - 2);
  fac[0] = 1;
  fac[1] = 1;
  for (i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= mod;
  }
  facinv[0] = facinv[1] = 1;
  for (i = 2; i <= n; i++) {
    facinv[i] = facinv[i - 1] * mulinv[i];
    facinv[i] %= mod;
  }
  a = b = x = y = k = 0;
  bool ok = true, ok2 = false, ok3 = false;
  for (i = 0; i < n; i++) {
    cin >> str;
    if (str[0] == '?')
      x++;
    else if (str[0] == 'B')
      a++;
    if (str[1] == '?')
      y++;
    else if (str[1] == 'W')
      b++;
    if (str[0] == '?' && str[1] == '?') k++;
    if (str == "BB" || str == "WW") ok = false;
    if (str == "BW" || str == "B?" || str == "?W") ok2 = true;
    if (str == "WB" || str == "W?" || str == "?B") ok3 = true;
  }
  if (a < b) {
    swap(a, b);
    swap(x, y);
  }
  sum = 0;
  for (i = 0; i <= x; i++) {
    c = a + i - b;
    if (c > y) break;
    z = choose(x, i) * choose(y, c);
    z %= mod;
    sum += z;
    sum %= mod;
  }
  if (ok) {
    sum2 = 1;
    for (i = 0; i < k; i++) {
      sum2 *= 2;
      sum2 %= mod;
    }
    if (!(ok2 && ok3)) {
      if (ok2 || ok3) {
        sum2 += mod - 1;
        sum2 %= mod;
      } else {
        sum2 += mod - 2;
        sum2 %= mod;
      }
    }
    sum += mod - sum2;
    sum %= mod;
  }
  cout << sum;
}
