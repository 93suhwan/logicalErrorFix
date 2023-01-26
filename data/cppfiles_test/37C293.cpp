#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<bool> mid(n + 1, false);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      mid[b] = true;
    }
    bool ok = false;
    for (int i = 1; i <= n && !ok; i++)
      if (!mid[i]) {
        ok = true;
        for (int j = 1; j <= n; j++)
          if (j != i) cout << i << " " << j << endl;
      }
  }
}
