#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  if (n % 2 == 0) {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] >= a[i + 1]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
