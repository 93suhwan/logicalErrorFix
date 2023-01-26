#include <bits/stdc++.h>
using namespace std;
int solve(string& s);
int solve(string& s) {
  int n = static_cast<int>(s.size()), n0b = 0;
  for (int i = 0; i < n; i++) {
    if (s.at(i) == '0') {
      if (i == n - 1) {
        n0b++;
      }
    } else {
      if (i > 0 && s.at(i - 1) == '0') {
        n0b++;
      }
    }
    if (n0b > 1) {
      return 2;
    }
  }
  return n0b ? 1 : 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  string s;
  cin >> tt;
  while (tt--) {
    cin >> s;
    cout << solve(s) << '\n';
  }
  return 0;
}
