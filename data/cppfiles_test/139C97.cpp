#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if (n % 2 != 0)
    cout << "NO" << endl;
  else if (s.substr(0, n / 2) == s.substr(n / 2, n / 2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int32_t main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
