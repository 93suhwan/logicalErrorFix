#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int zero = 0, one = 0;
  for (auto i = 0; i < n; i++) {
    if (s[i] == '0')
      zero++;
    else
      one++;
  }
  if (zero == 0) {
    cout << 0 << "\n";
    return;
  }
  if (one == 0) {
    cout << 1 << "\n";
    return;
  }
  long long int i1 = -1, i2 = -1;
  for (auto i = 0; i < n; i++) {
    if (s[i] == '0') {
      i1 = i;
      break;
    }
  }
  reverse(s.begin(), s.end());
  for (auto i = 0; i < n; i++) {
    if (s[i] == '0') {
      i2 = n - i - 1;
      break;
    }
  }
  reverse(s.begin(), s.end());
  bool flag = true;
  for (long long int i = i1; i <= i2; i++) {
    if (s[i] == '1') {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << 1 << "\n";
  } else
    cout << 2 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
