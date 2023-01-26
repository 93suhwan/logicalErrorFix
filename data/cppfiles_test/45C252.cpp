#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int s = 1;
  if (a[0] == 1) s++;
  int c = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0 && a[i - 1] == 0) {
      cout << -1 << "\n";
      ;
      return;
    } else if (a[i] == 1 && a[i - 1] == 1) {
      s += 5;
    } else if (a[i] == 1 && a[i - 1] == 0) {
      s++;
    } else
      s += 0;
  }
  cout << s << "\n";
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
