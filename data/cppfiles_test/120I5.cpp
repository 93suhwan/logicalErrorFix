#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    int k = 1;
    while (k <= r) {
      ans = max(ans, min(r + 1, k * 2) - k);
      k *= 2;
    }
    cout << min(r - l + 1 - ans, (r - l + 1) / 2) << "\n";
  }
  return 0;
}
