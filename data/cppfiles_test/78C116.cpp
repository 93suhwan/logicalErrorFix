#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, sum[N], x, maxx, ans[N];
void change(int x) {
  int cnt = 1;
  while (x != 0) {
    if (x % 2 == 1) sum[cnt]++;
    x /= 2;
    cnt++;
  }
  maxx = max(maxx, cnt);
  return;
}
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  cin >> t;
  while (t--) {
    maxx = 0;
    memset(sum, 0, sizeof sum);
    memset(ans, 0, sizeof ans);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      change(x);
    }
    int g = 0;
    for (int i = 1; i <= maxx; i++) g = gcd(sum[i], g);
    int sq = sqrt(g);
    for (int i = 1; i <= sq; i++) {
      if (g % i == 0) ans[++ans[0]] = i;
    }
    if (g == 0) {
      for (int i = 1; i <= n; i++) printf("%d ", i);
      puts("");
      continue;
    }
    if (sq * sq == g) {
      for (int i = 1; i <= ans[0]; i++) printf("%d ", ans[i]);
      for (int i = ans[0] - 1; i >= 1; i--) printf("%d ", g / ans[i]);
    } else {
      for (int i = 1; i <= ans[0]; i++) printf("%d ", ans[i]);
      for (int i = ans[0]; i >= 1; i--) printf("%d ", g / ans[i]);
    }
    puts("");
  }
  return 0;
}
