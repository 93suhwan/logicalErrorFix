#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, M = 2e5 + 10, mod = 1e9 + 7;
int n, k;
int qmi(int a, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * a % mod;
    a = (long long)a * a % mod;
    k >>= 1;
  }
  return res;
}
void solve() {
  cin >> n >> k;
  int res = 0;
  while (k) {
    int p = log(k) / log(2), q = qmi(n, p);
    res = (res + q) % mod;
    k -= qmi(2, p);
  }
  cout << res << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
