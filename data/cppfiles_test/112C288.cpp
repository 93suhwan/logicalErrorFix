#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  if (b > a) swap(a, b);
  if (c > a) swap(a, c);
  int mx = a + b + c - 3;
  int mn = max(a - 1 - (b + c), 0);
  if (m >= mn && m <= mx) {
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
