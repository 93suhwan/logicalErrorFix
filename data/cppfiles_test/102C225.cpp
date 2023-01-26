#include <bits/stdc++.h>
long double pi = acos(-1.0);
const int mod = 998244353;
using namespace std;
long long add(long long x, long long y) { return (x % mod + y % mod) % mod; }
long long sub(long long x, long long y) { return (x % mod - y % mod) % mod; }
long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1) {
    long long b = binpow(a, n - 1ll);
    return mul(b, a);
  } else {
    long long b = binpow(a, n / 2ll);
    return mul(b, b);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout.setf(ios::fixed);
  int t;
  cin >> t;
  for (int(tt) = 0; (tt) < t; (tt)++) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = 0, tp = 0;
    int lmx = 0, lmn = 0, tmx = 0, tmn = 0;
    int kk = 1;
    int x, y;
    for (int(i) = 0; (i) < s.size(); (i)++) {
      if (s[i] == 'L') {
        l--;
        lmn = min(lmn, l);
        if (lmx - lmn >= m) {
          kk = 0;
          lmn++;
          cout << 1 - tmn << " " << 1 - lmn << '\n';
          break;
        }
      }
      if (s[i] == 'R') {
        l++;
        lmx = max(lmx, l);
        if (lmx - lmn >= m) {
          kk = 0;
          cout << 1 - tmn << " " << 1 - lmn << '\n';
          break;
        }
      }
      if (s[i] == 'U') {
        tp--;
        tmn = min(tmn, tp);
        if (tmx - tmn >= n) {
          kk = 0;
          tmn++;
          cout << 1 - tmn << " " << 1 - lmn << '\n';
          break;
        }
      }
      if (s[i] == 'D') {
        tp++;
        tmx = max(tmx, tp);
        if (tmx - tmn >= n) {
          kk = 0;
          cout << 1 - tmn << " " << 1 - lmn << '\n';
          break;
        }
      }
    }
    if (kk) cout << 1 - tmn << " " << 1 - lmn << '\n';
  }
  return 0;
}
