#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 29;
char s[2010][2010];
int h[2010][2010];
pair<int, int> p[2010];
int l[2][2010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  ++n;
  ++m;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int j = 0; j < m; j++) {
    int p = -inf;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '1') p = i;
      h[i][j] = i - p;
    }
    p = inf + n;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i][j] == '1') p = i;
      if (h[i][j] > p - i) h[i][j] = p - i;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 2; k++) {
      int c = 0;
      for (int j = 0; j < m; j++) {
        if (h[i][j] >= inf) continue;
        pair<int, int> t = make_pair(h[i][j] * h[i][j] + j * j, 2 * j);
        while (c > 1 &&
               1ll * p[c - 2].first * (t.second - p[c - 2].second) -
                       1ll * p[c - 2].second * (t.first - p[c - 2].first) <=
                   1ll * p[c - 1].first * (t.second - p[c - 2].second) -
                       1ll * p[c - 1].second * (t.first - p[c - 2].first)) {
          --c;
        }
        p[c++] = t;
      }
      reverse(p, p + c);
      for (int j = 0; j < m; j++) {
        while (c && p[c - 1].second < 2 * j) {
          --c;
        }
        while (c > 1 && p[c - 2].first - p[c - 2].second * j <=
                            p[c - 1].first - p[c - 1].second * j) {
          --c;
        }
        l[k][j] = c ? p[c - 1].first - p[c - 1].second * j + j * j : inf;
      }
      reverse(h[i], h[i] + m);
    }
    for (int j = 0; j < m; j++) {
      ans += min(l[0][j], l[1][m - 1 - j]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
