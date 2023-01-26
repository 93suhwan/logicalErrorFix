#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::string;
using std::vector;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] - i - 1 > ans) ans = v[i] - i - 1;
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve();
}
