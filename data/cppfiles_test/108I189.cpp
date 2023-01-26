#include <bits/stdc++.h>
using namespace std;
const int MA = 1e5;
struct q {
  int a, h;
} o[MA + 5], oo[MA + 5];
int t, n, bi[MA + 5], nz[MA + 5];
bool ans[MA + 5];
bool cmp(q aa, q bb) { return aa.a > bb.a; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int hj = 1; hj <= n; hj++) {
      scanf("%d", &o[hj].a);
      o[hj].h = hj;
    }
    for (int hj = 1; hj <= n; hj++) {
      scanf("%d", &oo[hj].a);
      oo[hj].h = hj;
    }
    sort(o + 1, o + n + 1, cmp);
    sort(oo + 1, oo + n + 1, cmp);
    for (int fg = 1; fg <= n; fg++) {
      bi[oo[fg].h] = fg;
    }
    nz[n] = oo[bi[o[n].h]].a;
    for (int kl = n - 1; kl >= 1; kl--) {
      nz[kl] = max(nz[kl + 1], oo[bi[o[kl].h]].a);
    }
    int ma = oo[bi[o[1].h]].a;
    ans[o[1].h] = 1;
    for (int hj = 2; hj <= n; hj++) {
      if (nz[hj] > ma)
        ans[o[hj].h] = 1;
      else
        ans[o[hj].h] = 0;
    }
    for (int hj = 1; hj <= n; hj++) printf("%d", ans[hj]);
    printf("\n");
  }
  return 0;
}
