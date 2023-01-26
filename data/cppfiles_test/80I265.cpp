#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (i < n / 2) {
        cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << '\n';
        return;
      } else {
        cout << 1 << ' ' << i << ' ' << 1 << ' ' << i + 1 << '\n';
        return;
      }
    }
  }
  cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
