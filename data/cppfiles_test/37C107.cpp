#include <bits/stdc++.h>
using namespace std;
int t, n, m, a, b, c, root, r[100010];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    memset(r, 0, sizeof(r));
    root = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      r[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
      if (!r[i]) {
        root = i;
        break;
      }
    }
    if (root) {
      for (int i = 1; i <= n; i++) {
        if (i != root) {
          cout << root << " " << i << endl;
        }
      }
    }
  }
  return 0;
}
