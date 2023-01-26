#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void no() { cout << "NO" << '\n'; }
void yes() { cout << "YES" << '\n'; }
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int powe(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void solve() {
  long long int i, j, n, k1, k2, k3, k4, k;
  cin >> n;
  k = n / 3;
  k1 = n % 3;
  k1 = min(k1, 1ll);
  cout << k + k1 << " " << k << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, l, k, t, n;
  cin >> t;
  for (i = 1; i <= t; i++) {
    solve();
  }
}
