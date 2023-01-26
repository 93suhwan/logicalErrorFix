#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 1;
  if (a[0] == 1) l++;
  for (int i = 1; i < n; i++) {
    if (a[i] == 1) {
      if (a[i - 1] == 1)
        l = l + 5;
      else
        l++;
    } else {
      if (a[i - 1] == 0) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
