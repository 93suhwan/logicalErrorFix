#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int p[100005];
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      p[b] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (p[i] == 0) {
        ans = i;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i != ans) cout << i << ' ' << ans << endl;
    }
  }
}
