#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &a : v) cin >> a;
  int mn = *min_element(v.begin(), v.end());
  int count = n / 2;
  for (int i = 0; i < n and count; i++) {
    if (v[i] != mn) {
      cout << v[i] << ' ' << mn << '\n';
      count--;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
