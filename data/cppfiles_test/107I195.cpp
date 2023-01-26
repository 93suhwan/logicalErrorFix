#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int T, n, a[maxn], stk1[maxn], top1, stk2[maxn], top2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    int x, y;
    cin >> n >> x >> y;
    int sx = 0, sy = 0, fl = 0, px = n, py = 2;
    ;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
      if (i % 2 == 0)
        a[i] = px--, sx++;
      else
        a[i] = py++, sy++;
      if (sx == x && sy == y) {
        for (int j = 1; j <= i; j++) cout << a[j] << ' ';
        if (i % 2 == 0)
          for (int j = px; j >= py; j--) cout << j << ' ';
        else
          for (int j = py; j <= px; j++) cout << j << ' ';
        cout << '\n';
        fl = 1;
      }
    }
    if (fl) continue;
    sx = sy = fl = 0, a[1] = n, px = n - 1, py = 1;
    for (int i = 2; i <= n; i++) {
      if (i % 2 == 0)
        a[i] = py++, sy++;
      else
        a[i] = px--, sx++;
      if (sx == x && sy == y) {
        for (int j = 1; j <= i; j++) cout << a[j] << ' ';
        if (i % 2 == 0)
          for (int j = py; j <= px; j++) cout << j << ' ';
        else
          for (int j = px; j >= py; j--) cout << j << ' ';
        cout << '\n';
        fl = 1;
      }
    }
    if (fl) continue;
    cout << "-1\n";
  }
  return 0;
}
