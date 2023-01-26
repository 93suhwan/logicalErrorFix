#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int s = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      s++;
      if (i != 0 && a[i - 1] == 1) s += 4;
    } else
      c++;
    if (c == 2) {
      cout << -1 << "\n";
      ;
      return;
    }
  }
  cout << s + 1 << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
