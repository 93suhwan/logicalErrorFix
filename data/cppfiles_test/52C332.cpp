#include <bits/stdc++.h>
using namespace std;
int b[65], p = 1e9 + 7;
long long pow_(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1, a = a * a % p;
  }
  return res % p;
}
void solve(int n, int x) {
  int t = 0;
  long long ans = 0;
  while (x) {
    if (x & 1) ans = (ans + pow_(n, t)) % p;
    x >>= 1, t++;
  }
  cout << ans % p << endl;
}
int main() {
  ios::sync_with_stdio(!true);
  int t, n, k;
  cin >> t;
  while (t--) cin >> n >> k, solve(n, k);
}
