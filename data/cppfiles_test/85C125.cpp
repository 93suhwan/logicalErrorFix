#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int n = s.length();
  bool zero = true, one = true;
  for (auto i = 0; i < n; i++) {
    if (s[i] == '0') zero = false;
    if (s[i] == '1') one = false;
  }
  if (zero) {
    cout << 0 << "\n";
    return;
  }
  if (one) {
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
  for (long long int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      i2 = i;
      break;
    }
  }
  bool flag = false;
  for (long long int i = i1; i <= i2; i++) {
    if (s[i] == '1') {
      flag = true;
      break;
    }
  }
  if (!flag) {
    cout << 1 << "\n";
  } else {
    cout << 2 << "\n";
  }
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
