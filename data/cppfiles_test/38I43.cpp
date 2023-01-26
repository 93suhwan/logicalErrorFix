#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2) % mod;
  if (b % 2)
    return (res * res * a) % mod;
  else
    return (res * res) % mod;
}
void solve() {
  long long int n;
  n = 17;
  long long int x, y, z, w;
  if (n % 6 == 0) {
    cout << (n / 6) * 15 << endl;
    return;
  }
  if (n % 8 == 0) {
    cout << (n / 8) * 20 << endl;
    return;
  }
  if (n % 10 == 0) {
    cout << (n / 10) * 25 << endl;
    return;
  }
  if (n % 14 == 0) {
    cout << (n / 14) * 35 << endl;
  }
  x = n / 6;
  y = n / 8;
  z = n / 10;
  w = n / 14;
  long long int p, q, r, s;
  p = (x + 1) * 6 - n;
  q = (y + 1) * 8 - n;
  r = (z + 1) * 10 - n;
  s = (w + 1) * 14 - n;
  if (p <= q && p <= r && p <= s) {
    cout << (x + 1) * 15 << endl;
    return;
  }
  if (q <= r && q <= p && q <= s) {
    cout << (y + 1) * 20 << endl;
    return;
  }
  if (r <= q && r <= p && r <= s) {
    cout << (z + 1) * 25 << endl;
    return;
  }
  if (s <= r && s <= q && s <= p) {
    cout << (w + 1) * 35 << endl;
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1, k, z, c, i, j, n;
  cin >> t;
  while (t--) {
    solve();
  }
}
