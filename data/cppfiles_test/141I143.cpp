#include <bits/stdc++.h>
using namespace std;
long long int const MOD = 1e9 + 7;
long long mod(long long x) { return ((x % MOD + MOD) % MOD); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mulitiply(long long a, long long b) { return mod(mod(a) * mod(b)); }
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int qrt(long long int x) {
  long long int lo = 1, hi = ((2000000ll > x) ? x : 2000000ll);
  while (hi - lo > 1) {
    long long int mid = (lo + hi) / 2;
    if (mid * mid * mid < x) {
      lo = mid;
    } else
      hi = mid;
  }
  if (hi * hi * hi <= x)
    return hi;
  else
    return lo;
}
void Sieve_Erthenes(long long int n) {
  vector<bool> prm(n + 1, true);
  prm[0] = prm[1] = false;
  for (long long int i = 2; i * i <= n; i++) {
    if (prm[i]) {
      for (long long int j = i * i; j <= n; j += i) prm[j] = false;
    }
  }
  for (long long int push = 2; push <= n; push++)
    if (prm[push]) cout << push << " ";
}
long long int binExpo(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * (a)*1ll) % m;
    a = (a * 1ll * a) % m;
    b >>= 1;
  }
  return res;
}
long long int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
long long int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1},
              YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test_case;
  cin >> test_case;
  while (test_case--) {
    long long int a, s, f = 0;
    cin >> a >> s;
    long long int res = 0;
    vector<long long int> v;
    long long int ofa, ofs;
    while (s > 0) {
      ofa = a % 10;
      a /= 10;
      ofs = s % 10;
      s /= 10;
      if (ofs < ofa) {
        ofs = ofs + (s % 10) * 10;
        s /= 10;
      }
      if ((ofs - ofa) > 9) {
        f = 1;
        break;
      }
      v.push_back(ofs - ofa);
    }
    if (a) f = 1;
    long long int saur = 1;
    if (f)
      cout << -1;
    else {
      for (long long int i = v.size() - 1; i >= 0; i--)
        if (v[i] == 0 && saur == 1)
          continue;
        else {
          cout << v[i];
          saur = 0;
        }
    }
    cout << '\n';
  }
  return 0;
}
