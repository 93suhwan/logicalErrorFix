#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Solve() {
  i64 n, k;
  cin >> n >> k;
  i64 x = 1, ans = 0;
  while (x < k) {
    x *= 2;
    ans++;
    if (x >= n) {
      cout << ans << '\n';
      return;
    }
  }
  n -= x;
  ans += (n + k - 1) / k;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
}
