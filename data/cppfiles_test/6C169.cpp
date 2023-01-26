#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n, 0);
  int ans = n;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x > y) swap(x, y);
    if (A[x] == 0) ans--;
    A[x]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int z;
    cin >> z;
    if (z == 1) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      if (x > y) swap(x, y);
      if (A[x] == 0) ans--;
      A[x]++;
    } else if (z == 2) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      if (x > y) swap(x, y);
      A[x]--;
      if (A[x] == 0) ans++;
    } else if (z == 3)
      cout << ans << endl;
  }
}
int main() {
  solve();
  return 0;
}
