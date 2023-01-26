#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (*min_element(a, a + n))
    cout << "-1" << endl;
  else if (*max_element(a, a + n) == 0 || a[n - 1] == 0) {
    for (int i = 0; i <= n; i++) cout << i + 1 << " ";
    cout << endl;
    return;
  } else {
    int p;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
        p = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
      if (i == p) cout << n + 1 << " ";
    }
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
