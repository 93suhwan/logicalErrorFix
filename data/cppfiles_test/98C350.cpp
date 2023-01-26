#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
long long t, j, k, b, x(0), y(0), z, n, m;
void solve() {
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return;
    }
  }
  cout << -1 << " " << -1 << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
