#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] == 1) {
    cout << n + 1 << " ";
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    return;
  }
  if (a[n - 1] == 0) {
    for (int i = 0; i <= n; i++) {
      cout << i + 1 << " ";
    }
    return;
  }
  bool f = 0;
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " ";
    if (a[i] == 0 and a[i + 1] == 1 and !f) {
      f = 1;
      cout << n + 1 << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
