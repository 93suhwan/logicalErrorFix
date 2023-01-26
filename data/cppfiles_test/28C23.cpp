#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << (a + b * 2 + c * 3) % 2 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
