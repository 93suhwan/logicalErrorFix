#include <bits/stdc++.h>
using namespace std;
int t, n, s, c[300005];
char x, a[300005];
struct edg {
  int x, y;
} b[300005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> t;
  while (t--) {
    s = 0;
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] != x) {
        b[++s].x = i;
        b[s].y = 1;
      }
    }
    for (int j = 2; j <= n; j++) {
      int flag = 0;
      for (int i = 1; i <= s; i++) {
        if (b[i].x % j != 0 && b[i].y) {
          b[i].y = 0;
          c[j] = 1;
          continue;
        }
        if (b[i].y) {
          flag = 1;
        }
      }
      if (flag == 0) break;
    }
    if (s == 0)
      cout << "0" << endl;
    else {
      int sum = 0;
      for (int i = 2; i <= n; i++) {
        if (c[i]) sum++;
      }
      cout << sum << endl;
      for (int i = 2; i <= n; i++) {
        if (c[i]) cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
