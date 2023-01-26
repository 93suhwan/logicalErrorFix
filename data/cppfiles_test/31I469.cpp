#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  if (n % 2) {
    for (int i = 1; i <= n; i++) {
      if (i % 2)
        cout << a[i] << " ";
      else
        cout << -1 * a[i] << " ";
    }
    cout << endl;
  } else {
    for (int i = 1; i <= n - 3; i++) {
      if (i % 2)
        cout << a[i] << " ";
      else
        cout << -1 * a[i] << " ";
    }
    int x = a[n - 2] + a[n - 1];
    int y = a[n];
    cout << a[n] << " " << a[n] << " ";
    cout << -1 * x << endl;
  }
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
