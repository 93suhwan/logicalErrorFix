#include <bits/stdc++.h>
using namespace std;
const int MA = 1e5 + 5;
struct qwq {
  int zh, hh;
} a[MA], b[MA];
int t, n, ho[MA], qi[MA];
int aaa[MA];
bool cmp(qwq aa, qwq bb) { return aa.zh > bb.zh; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].zh);
      a[i].hh = i;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &b[i].zh);
      b[i].hh = i;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int io = 1; io <= n; io++) {
      ho[b[io].hh] = io;
    }
    for (int az = n; az >= 1; az--) {
      qi[az] = max(qi[az + 1], b[ho[a[az].hh]].zh);
    }
    aaa[a[1].hh] = 1;
    int ans = b[ho[a[1].hh]].zh, aa = ans;
    for (int io = 2; io <= n; io++) {
      if (qi[io] < ans)
        aaa[a[io].hh] = 0;
      else {
        aaa[a[io].hh] = 1;
        aa = min(aa, b[ho[a[io].hh]].zh);
        ans = min(ans, aa);
      }
      aa = min(aa, b[ho[a[io].hh]].zh);
    }
    for (int io = 1; io <= n; io++) printf("%d", aaa[io]);
    printf("\n");
  }
  return 0;
}
