#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, t, res;
struct sb {
  int x, y;
  bool operator<(const sb a) const {
    if (x < a.y && a.x >= y) return 1;
    if (a.x < y && x >= a.y) return 0;
    if (y >= a.y && x <= a.x) return 0;
    return y < a.y;
  }
} s[500500];
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &s[i].x, &s[i].y);
  }
  puts("");
  sort(s + 1, s + n + 1);
  for (i = 1; i <= n; i++) {
    if (s[i].x < m) continue;
    res++;
    m = max(m, s[i].y);
  }
  cout << res;
}
