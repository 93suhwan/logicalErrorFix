#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  string s;
  cin >> n >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (n - i - 1 >= n / 2) {
        cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << endl;
        return;
      }
      if (i >= n / 2) {
        cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << endl;
        return;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
}
