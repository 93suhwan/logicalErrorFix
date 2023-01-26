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
  long long res = 0;
  for (int j = 31; j >= 0; j--)
    if (k >> j & 1) res = (res + qmi(n, j)) % mod;
  cout << res << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
