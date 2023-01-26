#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, m;
  cin >> n >> m;
  ++m;
  int ans = 0;
  for (int k = 30; k >= 0; k--) {
    if (n >= m) continue;
    if ((n >> k & 1) == (m >> k & 1)) continue;
    if (m >> k & 1) {
      ans |= 1 << k;
      n |= 1 << k;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) cout << solve() << "\n";
}
