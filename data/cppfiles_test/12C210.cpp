#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k;
void solve() {
  int yoko = k, tate = n * m / 2 - k;
  while (1) {
    if (yoko % 2 == 0 && tate % 2 == 0 && n % 2 == 0 && m % 2 == 0) {
      cout << "YES" << endl;
      return;
    } else if (n % 2) {
      n--;
      yoko -= m / 2;
      if (yoko < 0) break;
    } else if (m % 2) {
      m--;
      tate -= n / 2;
      if (tate < 0) break;
    } else
      break;
  }
  cout << "NO" << endl;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    solve();
  }
}
