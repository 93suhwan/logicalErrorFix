#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a;
  cin >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i] and a[i] == '1') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
