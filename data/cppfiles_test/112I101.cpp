#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int m;
  vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i];
  }
  cin >> m;
  sort(a.rbegin(), a.rend());
  int sum = a[0] + a[1] + a[2];
  if (m > a[0] + a[1] + a[2] - 3) {
    cout << "NO\n";
    return;
  }
  if (a[0] - a[1] - a[2] >= 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
