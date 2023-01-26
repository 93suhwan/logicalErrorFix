#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
long long inv(long long a) {
  long long x, y;
  gcd(a, MOD, x, y);
  return (x % MOD + MOD) % MOD;
}
long long fact(long long a) {
  long long res = 1;
  for (long long i = 2; i <= a; ++i) res = res * i % MOD;
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  long long powerP = 0, powerX = 0, count = 1;
  bool flagBW = false, flagWB = false;
  for (long long i = 0; i < n; ++i) {
    string d;
    cin >> d;
    if (d == "BB" || d == "WW") count = 0;
    if (d == "BB")
      powerX += 2;
    else if (d == "BW") {
      ++powerX;
      flagBW = true;
    } else if (d == "WB") {
      ++powerX;
      flagWB = true;
    } else if (d == "??") {
      powerP += 2;
      count = 2 * count % MOD;
    } else if (d != "WW") {
      if (d.find('B') != -1) {
        ++powerP;
        ++powerX;
        d[d.find('?')] = 'W';
      } else {
        ++powerP;
        d[d.find('?')] = 'B';
      }
      if (d == "BW")
        flagBW = true;
      else
        flagWB = true;
    }
  }
  long long k = n - powerX;
  if (k < 0 || powerP < k)
    cout << 0;
  else {
    long long ans =
        (fact(powerP) * inv(fact(k)) % MOD) * inv(fact(powerP - k)) % MOD;
    if (count > 0) ans = (ans - count + !flagBW + !flagWB + MOD) % MOD;
    cout << ans;
  }
  return 0;
}
