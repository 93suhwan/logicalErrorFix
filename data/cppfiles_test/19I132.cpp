#include <bits/stdc++.h>
using namespace std;
int a[15];
void solve() {
  int n;
  cin >> n;
  int f = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= 0) f = 1;
  }
  if (f)
    cout << "YES" << endl;
  else {
    sort(a + 1, a + 1 + n);
    int d = a[2] - a[1];
    for (int i = 2; i <= n; i++) {
      if (a[i] - a[i - 1] != d) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
