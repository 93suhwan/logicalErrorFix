#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      int x = c - '0';
      if (i == n && x) {
        ans += x;
        break;
      }
      if (x) ans += x + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
