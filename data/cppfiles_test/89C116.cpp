#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  bool b;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    b = 0;
    for (int j = 2; j <= i + 2; j++) {
      if ((v[i] % j)) {
        b = 1;
        break;
      }
    }
    if (!b) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
