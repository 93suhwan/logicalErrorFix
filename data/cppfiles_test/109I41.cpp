#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long mod = 998244353;
int n;
string s;
long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return r;
}
long long C(int a, int b) {
  if (b >= a || b < 0) return 0;
  long long r = 1;
  for (int i = 1; i <= a; ++i) r = r * i % mod;
  for (int i = 1; i <= b; ++i) r = r * qpow(i, mod - 2) % mod;
  for (int i = 1; i <= a - b; ++i) r = r * qpow(i, mod - 2) % mod;
  return r;
}
int main() {
  cin >> n;
  int c1 = 0, c2 = 0;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  long long w = 1;
  int flag1 = 0, flag2 = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    int cc0 = 0;
    if (s[0] == 'B' || s[1] == 'W') flag1 = 1;
    if (s[1] == 'B' || s[0] == 'W') flag2 = 1;
    for (int j = 0; j < 2; ++j) {
      if (s[j] == 'B')
        ++cnt0;
      else if (s[j] == 'W')
        ++cnt1;
      else
        ++cnt2, ++cc0;
    }
    if (s == "BW")
      c1++;
    else if (s == "WB")
      c2++;
    else if (!cc0)
      w = 0;
    else if (cc0 == 2)
      w = w * 2 % mod;
  }
  int det = abs(cnt0 - cnt1);
  if (!cnt2) {
    if (det > 0 || (c1 && c2 && c1 + c2 == n))
      puts("0");
    else
      puts("1");
    return 0;
  }
  long long ans = C(cnt2, (det + cnt2) / 2);
  ans = (ans - w + mod) % mod;
  int g = 2 - flag1 - flag2;
  ans = (ans + g) % mod;
  cout << ans << endl;
}
