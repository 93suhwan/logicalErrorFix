#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long l = -1, r = -1;
  for (long long i = 0; i < n - 1; i++) {
    if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a')) {
      l = i;
      r = i + 1;
      break;
    }
  }
  if (l + r != -2)
    cout << l + 1 << " " << r + 1 << '\n';
  else
    cout << l << " " << r << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long _ = 1;
  cin >> _;
  for (long long tc = 1; tc <= _; tc++) {
    solve();
  }
}
