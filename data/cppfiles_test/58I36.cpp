#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 1e9 + 7;
void solve() {
  int n;
  string s, c;
  cin >> n;
  cin >> s >> c;
  for (int i = 1; i < n; i++) {
    if (s[i] == '1' && c[i] == '1' && (s[i - 1] == '1' || c[i - 1] == '1')) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
