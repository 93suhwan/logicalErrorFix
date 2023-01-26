#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int n, m, a[10], x, y;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    mp[pair<int, int>(x, y)] = 1;
    mp[pair<int, int>(y, x)] = 1;
  }
  int t = min(50, n);
  int p1, p2;
  for (int i = 1; i <= t; i++)
    for (int j = i + 1; j <= t; j++)
      for (int k = j + 1; k <= t; k++)
        for (int l = k + 1; l <= t; l++)
          for (int p = l + 1; p <= t; p++) {
            a[0] = i;
            a[1] = j;
            a[2] = k;
            a[3] = l;
            a[4] = p;
            p1 = p2 = 1;
            for (int q = 0; q < 5; q++)
              for (int w = 0; w < 5; w++) {
                if (q == w) continue;
                if (!mp[pair<int, int>(a[q], a[w])])
                  p1 = 0;
                else
                  p2 = 0;
              }
            if (p1 || p2) {
              cout << i << ' ' << j << " " << k << " " << l << " " << p << endl;
              return 0;
            }
          }
  cout << -1 << endl;
  return 0;
}
