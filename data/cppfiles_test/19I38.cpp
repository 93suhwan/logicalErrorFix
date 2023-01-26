#include <bits/stdc++.h>
using namespace std;
using lld = long long int;
using llu = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using piii = pair<pii, int>;
mt19937 rnd;
int nextint(int s, int t) { return (int)(rnd() % (t - s + 1)) + s; }
int n, m, p;
int a[10009];
set<int> b[2][1009][2009];
queue<pii> que[2];
const int M = 1000;
int main() {
  int t = 1, tv = 0;
  int i, j, k, l;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int l = 0;
    int r = 2002;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    l = a[0];
    int res = r;
    int cur = 0;
    int nxt = 1;
    que[cur].push(pii(0, 0));
    b[cur][0][0].insert(0);
    for (i = 0; i < n; i++) {
      while (!que[cur].empty()) {
        pii qq = que[cur].front();
        que[cur].pop();
        for (auto &it : b[cur][qq.first][qq.second]) {
          {
            int jt = it - a[i];
            pii tt;
            tt.first = max(qq.first, -jt);
            tt.second = max(jt + tt.first, qq.second + (tt.first - qq.first));
            if (tt.first <= 1000 && tt.second <= tt.first + 1000) {
              if (b[nxt][tt.first][tt.second].size() == 0) {
                que[nxt].push(tt);
              }
              b[nxt][tt.first][tt.second].insert(jt);
            }
          }
          {
            int jt = it + a[i];
            pii tt;
            tt.first = max(qq.first, -jt);
            tt.second = max(jt + tt.first, qq.second + (tt.first - qq.first));
            if (tt.first <= 1000 && tt.second <= tt.first + 1000) {
              if (b[nxt][tt.first][tt.second].size() == 0) {
                que[nxt].push(tt);
              }
              b[nxt][tt.first][tt.second].insert(jt);
            }
          }
        }
        b[cur][qq.first][qq.second].clear();
      }
      cur ^= true;
      nxt ^= true;
    }
    res = 2001;
    while (!que[cur].empty()) {
      pii qq = que[cur].front();
      que[cur].pop();
      res = min(res, qq.second);
      b[cur][qq.first][qq.second].clear();
    }
    printf("%d\n", res);
  }
}
