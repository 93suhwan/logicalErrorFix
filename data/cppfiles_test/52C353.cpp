#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long res = 0, cur = 1;
  while (k > 0) {
    if (k % 2 == 1) res = (res + cur) % mod;
    cur = (cur * n) % mod;
    k /= 2;
  }
  cout << res << "\n";
}
int main() {
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
