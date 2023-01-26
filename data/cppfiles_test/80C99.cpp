#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int mid = n / 2;
  long long int check = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '0') {
      check = 1;
      if (i >= mid) {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        return;
      } else {
        cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
        return;
      }
    }
  }
  if (check == 0) {
    cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
  }
}
int32_t main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
