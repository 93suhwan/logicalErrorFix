#include <bits/stdc++.h>
using namespace std;
void fileio() {}
void solve() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << endl;
    return;
  }
  long long ans = 0;
  m++;
  for (auto i = 32 - 1; i >= 0; i--) {
    int x = (n >> i) & 1;
    int y = (m >> i) & 1;
    if (x == 1 && y == 0) break;
    if (x == 0 && y == 1) ans |= (1 << i);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  fileio();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
