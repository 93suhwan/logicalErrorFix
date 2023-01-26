#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      a[i] = 1;
      b[i] = 0;
    } else {
      a[i] = 0;
      b[i] = 1;
    }
    if (i) {
      a[i] += a[i - 1];
      b[i] += b[i - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((i == 0 && b[j] == a[j]) ||
          (i != 0 && ((b[j] - b[i - 1]) == (a[j] - a[i - 1])))) {
        cout << i + 1 << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "-1 -1\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
