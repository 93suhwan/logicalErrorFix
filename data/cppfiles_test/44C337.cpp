#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long b, long long e) {
  if (!e) return 1;
  if (e % 2) return b * fastpow(b, e - 1);
  long long x = fastpow(b, e / 2);
  return x * x;
}
long long PowMod(long long b, long long e) {
  if (!e) return 1;
  long long p = PowMod((b * b) % 1000000007, e / 2);
  return (e % 2) ? (p * b) % 1000000007 : p;
}
long long ModInverse(long long a) { return PowMod(a, 1000000007 - 2); }
const long long pMAX = 10000001;
bool prime[pMAX];
void init() {}
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a == 0 && b == 0) {
    cout << 0 << '\n';
    return;
  }
  if (a == b) {
    cout << 1 << '\n';
    return;
  }
  long long c = abs(a - b);
  if (c & 1) {
    cout << -1 << '\n';
    return;
  }
  cout << 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
