#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      cout << i + 1 << " " << i + 2 << "\n";
      return;
    }
  }
  cout << "-1 -1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
