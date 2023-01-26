#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int l = 0, r = 0;
  for (long long int f = 0; f < s.length(); f++) {
    if (f % 2) {
      l *= 10;
      l += s[f] - '0';
    } else {
      r *= 10;
      r += s[f] - '0';
    }
  }
  cout << (l + 1) * (r + 1) - 2;
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt;
  cin >> tt;
  long long int ll = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
