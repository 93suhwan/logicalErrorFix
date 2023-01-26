#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
void solve(void) {
  string str;
  cin >> str;
  int one = 0, zero = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '1')
      one++;
    else
      zero++;
  }
  if (one && zero) {
    if (zero <= 1)
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  } else if (zero)
    cout << 1 << '\n';
  else if (one)
    cout << 0 << '\n';
}
int main(void) {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
