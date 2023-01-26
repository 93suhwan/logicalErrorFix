#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long pwr(long long a, long long x) {
  long long res = 1;
  while (x) {
    if (x & 1) {
      res = (res * a) % mod;
      x--;
    } else {
      a = (a * a) % mod;
      x /= 2;
    }
  }
  return res;
}
const long long N = 3e5 + 5;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (m < n - 2 || m > n * (n - 1) / 2 || k <= 2) {
    cout << "NO"
         << "\n";
    return;
  }
  if (k < 2) {
    cout << "NO"
         << "\n";
    return;
  }
  if (k == 3 && m != n * (n - 1) / 2) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
