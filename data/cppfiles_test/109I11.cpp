#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
const long long mod = 998244353;
const long long inf = 1e18;
long long pw(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return c;
}
long long n, x, c, o1, o2;
long long C(long long a, long long b) {
  if (b > a) return 0;
  if (b < 0) return 0;
  long long c = 1;
  for (long long i = 0; i < b; i++) {
    c = c * (a - i) % mod;
    c = c * pw(i + 1, mod - 2) % mod;
  }
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long t = 1;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'W' || s[1] == 'B') o1 = 1;
    if (s[0] == 'B' || s[1] == 'W') o2 = 1;
    if (s == "BB" || s == "WW") t = 0;
    if (s == "??") {
      x += 2;
      c++;
      t = t * 2 % mod;
      continue;
    }
    long long j = 0;
    if (s[0] == '?') j = 1;
    if (s[1 - j] == 'B') {
      c--;
      continue;
    }
    if (s[1 - j] == 'W') {
      c++;
      continue;
    }
    if (s[j] == 'B') {
      x++;
    } else {
      x++;
      c++;
    }
  }
  t -= 1 - o1;
  t -= 1 - o2;
  cout << ((C(x, c) - t) % mod + mod) % mod << "\n";
  return 0;
}
