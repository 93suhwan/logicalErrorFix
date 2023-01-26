#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e9;
const long long N = 200005;
long long binpow(long long a, long long ast) {
  long long res = 1;
  while (ast > 0) {
    if (ast & 1) {
      res *= a;
      res %= MOD;
    }
    a *= a;
    a %= MOD;
    ast >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  long long harc = 0;
  bool bw = 1, wb = 1;
  long long wbbw = 1;
  long long wqan = 0;
  for (long long i = (1); i < (n + 1); i++) {
    char a, b;
    cin >> a >> b;
    if (a == '?') {
      harc++;
    }
    if (b == '?') {
      harc++;
    }
    if (a == 'W' or b == 'B') {
      bw = 0;
    }
    if (a == 'B' or b == 'W') {
      wb = 0;
    }
    wqan += (a == 'W');
    wqan += (b == 'W');
    if (a == b and a != '?') {
      wbbw = 0;
    } else if (wbbw != 0) {
      if (a == '?' and b == '?') {
        wbbw *= 2;
        wbbw %= MOD;
      }
    }
  }
  if (wqan > n or 2 * n - wqan - harc > n) {
    cout << 0 << endl;
    return 0;
  }
  long long o = 1;
  for (long long i = (n - wqan + 1); i < (harc + 1); i++) {
    o *= i;
    o %= MOD;
  }
  long long oo = 1;
  for (long long i = (1); i < (harc - (n - wqan) + 1); i++) {
    oo *= i;
    oo %= MOD;
  }
  long long ans1 = o * (binpow(oo, MOD - 2)) % MOD;
  cout << (ans1 - wbbw + bw + wb + MOD) % MOD << endl;
  return 0;
}
