#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
  for (int i = 0; i < n; i++) {
    if (l[i] == r[i])
      cout << l[i] << " " << r[i] << " " << l[i] << '\n';
    else {
      int ego = l[i] - 1;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          if (l[i] == l[j]) {
            if (l[i] <= l[j] and r[j] <= r[i]) {
              ego = max(ego, r[j]);
            }
          }
        }
      }
      cout << l[i] << " " << r[i] << " " << ego + 1 << "\n";
    }
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
