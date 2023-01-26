#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, cnt = 0, mod = 1000000007, fin = 0;
  cin >> n >> k;
  while (k) {
    if (k % 2) {
      long long ans = 1;
      for (int i = 0; i < cnt; ++i) ans = (ans * n) % mod;
      fin = (fin + ans) % mod;
    }
    ++cnt;
    k /= 2;
  }
  cout << fin << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
