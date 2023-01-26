#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
long long mod = 1e9 + 7, p1[3000006], p2[3000006], d[3000006][3];
long long C(long long a, long long b) {
  return (p1[a] % mod * p2[b] % mod * p2[a - b] % mod) % mod;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, q;
  cin >> n >> q;
  p1[0] = 1;
  long long m = 3 * n + 1;
  for (long long i = 1; i <= m; i++) {
    p1[i] = p1[i - 1] * i;
    p1[i] %= mod;
  }
  p2[m] = qpow(p1[m], mod - 2);
  for (long long i = m - 1; i >= 0; i--) {
    p2[i] = p2[i + 1] * (i + 1) % mod;
  }
  d[0][1] = d[0][0] = d[0][2] = n;
  long long dn = qpow(3, mod - 2);
  for (long long i = 1; i < 3 * n; i++) {
    long long D = C(3 * n, i + 1);
    long long A = d[i - 1][0], B = d[i - 1][1];
    d[i][0] = ((D - 2 * A - B) % mod * dn % mod + mod) % mod;
    d[i][1] = (d[i][0] + A) % mod;
    d[i][2] = (d[i][1] + B) % mod;
  }
  while (q--) {
    long long x;
    cin >> x;
    cout << (d[x][0] + C(3 * n, x)) % mod << endl;
  }
}
