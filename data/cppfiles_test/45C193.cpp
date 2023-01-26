#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double eps = 1e-8;
const double PI = acos(-1);
const int maxn = 1e5 + 5;
int a[maxn], p0[maxn], p1[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int c0 = 0, c1 = 0;
    for (int i = (1); i <= (n); i++) {
      scanf("%d", &a[i]);
      a[i] %= 2;
      if (a[i] == 0)
        p0[++c0] = i;
      else
        p1[++c1] = i;
    }
    if (c0 == c1) {
      int res1 = 0, res2 = 0;
      for (int i = 1, p = 1; i <= c0; i++) {
        res1 += abs(p0[i] - p);
        p += 2;
      }
      for (int i = 1, p = 2; i <= c0; i++) {
        res2 += abs(p0[i] - p);
        p += 2;
      }
      printf("%d", min(res1, res2));
      puts("");
    } else if (c0 == c1 + 1) {
      int res = 0;
      for (int i = 1, p = 1; i <= c0; i++) {
        res += abs(p0[i] - p);
        p += 2;
      }
      printf("%d", res);
      puts("");
    } else if (c1 == c0 + 1) {
      int res = 0;
      for (int i = 1, p = 1; i <= c1; i++) {
        res += abs(p1[i] - p);
        p += 2;
      }
      printf("%d", res);
      puts("");
    } else
      puts("-1");
  }
}
