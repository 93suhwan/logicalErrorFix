#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void in() {}
void solve() {
  int n;
  cin >> n;
  int a[n];
  int mx = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int cnt = 0, nmx = a[n - 1];
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] >= nmx && a[i] != mx) {
      if (a[i] != nmx) {
        nmx = a[i];
        cnt++;
      }
    } else if (a[i] >= nmx && a[i] == mx) {
      if (nmx != mx) cnt++;
      break;
    }
  }
  cout << cnt << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, tc;
  t = 1, tc = 0;
  cin >> t;
  while (t--) {
    solve();
  }
}
