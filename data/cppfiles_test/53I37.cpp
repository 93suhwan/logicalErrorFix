#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  long long int o = 0, e = 0, cnt = 0;
  for (auto i : s) {
    if (i == c) cnt++;
  }
  if (cnt == 0) {
    cout << 0 << endl;
  } else {
    if (s[n - 1] == c) {
      cout << 1 << endl << n << endl;
    } else if (cnt == n - 1) {
      if (n % 2) {
        cout << 1 << endl << 2 << endl;
      } else {
        cout << 1 << endl << 3 << endl;
      }
    } else {
      if (n % 2) {
        cout << 2 << endl;
        cout << "2 " << n << endl;
      } else {
        cout << 2 << endl;
        cout << "3 " << n << endl;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
