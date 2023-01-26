#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r;
  bool g;
} e[1005];
inline bool cmp(node x, node y) { return x.r - x.l < y.r - y.l; }
int n;
int main() {
  int t;
  scanf("%d", &t);
  bool gg = 0;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &e[i].l, &e[i].r);
      e[i].g = 0;
    }
    sort(e + 1, e + n + 1, cmp);
    bool num[1005] = {0};
    if (gg)
      printf("\n");
    else
      gg = 1;
    int rest = n;
    vector<int> vv;
    for (int i = 1; i <= n; ++i) vv.push_back(i);
    while (rest) {
      for (int k = 0; k < rest; ++k) {
        int i = vv[k];
        if (e[i].g) continue;
        int kkk = 0, v;
        for (int j = e[i].l; j <= e[i].r; ++j) {
          if (!num[j]) {
            ++kkk;
            v = j;
            if (kkk >= 2) break;
          }
        }
        if (kkk == 1) {
          e[i].g = 1;
          num[v] = 1;
          printf("%d %d %d\n", e[i].l, e[i].r, v);
          vv.erase(vv.begin() + k);
          rest--;
        }
      }
    }
  }
  return 0;
}
