#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1' && b[i] == '1') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
