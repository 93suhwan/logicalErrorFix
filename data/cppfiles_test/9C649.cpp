#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  int f[27];
  for (long long int i = 0; i < 27; i++) {
    f[i] = 0;
  }
  int l = 0;
  cin >> s;
  for (long long int i = 0; i < s.length(); i++) {
    f[(s[i]) - '0' - 48]++;
  }
  for (long long int i = 0; i < 27; i++) {
    if (f[i] > 2) {
      l = l + f[i] - 2;
    }
  }
  int x = s.length() - l;
  cout << x / 2 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
