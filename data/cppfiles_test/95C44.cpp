#include <bits/stdc++.h>
using namespace std;
struct poi {
  int val, tp, id;
} p[1000005];
int T, n, m, ans = 0;
int lmx[500005], lmn[500005], col[500005];
vector<int> g[500005];
multiset<int> s[500005];
multiset<int> grt;
bool cmp(poi a, poi b) {
  if (a.val == b.val) return a.tp < b.tp;
  return a.val < b.val;
}
void update(int x) {
  grt.clear();
  for (int i = 1; i <= n; i++) {
    int ele = g[i][x - 1];
    lmx[i] = max(lmx[i], ele);
    lmn[i] = min(lmn[i], ele);
    s[i].erase(s[i].find(ele));
    p[2 * i - 1].val = lmx[i];
    p[2 * i].val = lmn[i];
    p[2 * i - 1].tp = 1;
    p[2 * i].tp = 0;
    p[2 * i - 1].id = i;
    p[2 * i].id = i;
    col[i] = 0;
    grt.insert(*s[i].begin());
  }
  sort(p + 1, p + 2 * n + 1, cmp);
}
int main() {
  multiset<int>::iterator it;
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      s[i].clear();
      lmx[i] = 0;
      lmn[i] = 1e7;
      for (int j = 1; j <= m; j++) {
        int a;
        scanf("%d", &a);
        g[i].push_back(a);
        s[i].insert(a);
      }
    }
    for (int i = 1; i < m; i++) {
      update(i);
      int top = 0, t = 0;
      for (int j = 2 * n; j >= 1; j--) {
        if (p[j].tp) t++;
        if (!p[j].tp) {
          t--;
          col[p[j].id] = 1;
          it = s[p[j].id].end();
          it--;
          top = max(top, *it);
          grt.erase(grt.find(*s[p[j].id].begin()));
        }
        if (t == 0 && !grt.empty()) {
          if (top < *grt.begin()) {
            ans = i;
            break;
          }
        }
      }
      if (ans) break;
    }
    if (ans) {
      printf("YES\n");
      for (int i = 1; i <= n; i++) {
        if (col[i])
          printf("R");
        else
          printf("B");
      }
      printf(" %d\n", ans);
    } else
      printf("NO\n");
  }
  return 0;
}
