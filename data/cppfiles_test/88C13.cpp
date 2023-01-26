#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int mod = 1e9 + 7;
const int N = 300 + 10;
int n, m, k, T, ans, cnt, sum;
pair<int, int> p[N * N];
int get(int x, int y) { return (x - 1) * m + y; }
int main(void) {
  scanf("%d", &T);
  while (T--) {
    ans = cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        int x;
        scanf("%d", &x);
        p[++cnt] = {x, cnt};
      }
    sort(p + 1, p + cnt + 1);
    for (int i = 1; i <= cnt; i++) p[i].second *= -1;
    for (int i = 1; i <= n; i++) {
      sort(p + get(i, 1), p + get(i, m) + 1);
      for (int j = 1; j <= m; j++)
        for (int k = 1; k < j; k++)
          ans += int(p[get(i, j)].second < p[get(i, k)].second);
    }
    printf("%d\n", ans);
  }
  return 0;
}
