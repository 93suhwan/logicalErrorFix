#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
bool b[100001];
int main() {
  cin >> T;
  while (T--) {
    memset(b, 0, sizeof(b));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      b[y] = 1;
    }
    int t;
    for (int i = 1; i <= n; i++) {
      if (!b[i]) {
        t = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != t) {
        cout << i << " " << t << endl;
      }
    }
  }
  return 0;
}
