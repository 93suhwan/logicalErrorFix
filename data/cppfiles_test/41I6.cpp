#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 1e9 + 7;
void solve() {
  int n, k;
  cin >> n >> k;
  cout << (n + k - 1) / k << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (i / k != j / k) {
        cout << i / k + 1 << " ";
      } else {
        if (i / k + 1 != (n + k - 1) / k) {
          cout << (n + k - 1) / k << " ";
        }
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  int cur = 1;
  while (t--) {
    solve();
  }
  return 0;
}
