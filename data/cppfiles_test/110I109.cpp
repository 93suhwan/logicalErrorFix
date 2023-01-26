#include <bits/stdc++.h>
using namespace std;
struct node {
  vector<long long> xg;
  long long sz, bh;
} s[200005], p[200005];
bool cmp(node x, node y) {
  if (x.sz != y.sz)
    return x.sz < y.sz;
  else
    return x.bh < y.bh;
}
bool cmp2(long long x, long long y) { return s[x].bh < s[y].bh; }
vector<long long> cc;
int main() {
  long long t, n, i, j, k, zc, sy, sg, zczc, slsl;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n), sy = n;
    for (i = 1; i <= n; i++) {
      s[i].xg.clear();
      s[i].bh = i, s[i].sz = 0;
    }
    for (i = 1; i <= n; i++) {
      scanf("%lld", &k);
      for (j = 1; j <= k; j++) {
        scanf("%lld", &zc);
        s[zc].xg.push_back(i);
        s[i].sz++;
      }
    }
    for (i = 1; i <= n; i++) {
      p[i].xg = s[i].xg;
      p[i].sz = s[i].sz;
      p[i].bh = i;
    }
    cc.clear();
    sort(p + 1, p + 1 + n, cmp);
    for (i = 1; i <= n; i++) {
      if (p[i].sz == 0)
        cc.push_back(p[i].bh);
      else
        break;
    }
    sg = -1, slsl = 1;
    while (cc.size() > 0) {
      zczc = cc[0];
      if (sg > zczc) {
        sg = -1;
        sort(cc.begin(), cc.end(), cmp2);
        slsl++;
        continue;
      }
      cc.erase(cc.begin());
      sy--;
      if (s[zczc].xg.size() == 0) continue;
      for (i = 0; i <= s[zczc].xg.size() - 1; i++) {
        s[s[zczc].xg[i]].sz--;
        if (s[s[zczc].xg[i]].sz == 0) cc.push_back(s[zczc].xg[i]);
      }
      if (sg == -1) sg = zczc;
    }
    if (sy == 0)
      printf("%lld\n", slsl);
    else
      printf("-1\n");
  }
  return 0;
}
