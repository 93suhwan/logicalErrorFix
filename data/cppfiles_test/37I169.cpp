#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    bool bs[n];
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      c--;
      bs[b] = true;
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
      if (!bs[i]) {
        root = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == root) continue;
      cout << root + 1 << " " << i + 1 << "\n";
    }
  }
  return 0;
}
