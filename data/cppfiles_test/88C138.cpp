#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    cout << "YES" << '\n';
    return;
  }
  bool flag = true;
  for (long long i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      flag = false;
    }
  }
  if (flag) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
