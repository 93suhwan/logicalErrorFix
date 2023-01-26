#include <bits/stdc++.h>
using namespace std;
int to[200005];
int main() {
  int n, m;
  cin >> n >> m;
  int ans = n;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    to[x]++;
    if (to[x] == 1) {
      ans--;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int sg;
    cin >> sg;
    if (sg == 1 || sg == 2) {
      int x, y;
      cin >> x >> y;
      if (x > y) {
        swap(x, y);
      }
      if (sg == 1) {
        to[x]++;
        if (to[x] == 1) {
          ans--;
        }
      } else {
        to[x]--;
        if (to[x] == 0) {
          ans++;
        }
      }
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
