#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int n;
int d[N];
int stkb[N], topb;
int stkr[N], topr;
char c[N];
void init() {}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = (1); i <= (n); i++) scanf("%d", &d[i]);
    topb = topr = 0;
    scanf("%s", c + 1);
    for (int i = (1); i <= (n); i++) {
      if (c[i] == 'B') {
        stkb[++topb] = d[i];
      } else {
        stkr[++topr] = d[i];
      }
    }
    sort(stkb + 1, stkb + 1 + topb);
    sort(stkr + 1, stkr + 1 + topr, greater<int>());
    bool f = 1;
    for (int i = (1); i <= (topb); i++) {
      if (i > stkb[i]) {
        f = 0;
        break;
      }
    }
    for (int i = (1); i <= (topr); i++) {
      if (n - i + 1 < stkr[i]) {
        f = 0;
        break;
      }
    }
    puts(f ? "YES" : "NO");
  }
  return 0;
}
