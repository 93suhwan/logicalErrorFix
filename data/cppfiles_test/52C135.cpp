#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(int a, int b) {
  long long ans = 1;
  for (int i = 0; i < b; i++) ans = (ans * a) % mod;
  return ans;
}
void doo() {
  int n, k;
  cin >> n >> k;
  long long res = 0;
  for (int i = 31; i >= 0; i--) {
    if (k & (1 << i)) {
      res += power(n, i);
      res %= mod;
    }
  }
  cout << res << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) doo();
  return 0;
}
