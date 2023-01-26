#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  if (m <= a - 1 + b - 1 + c - 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
