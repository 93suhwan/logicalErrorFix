#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
bool primeflag[N + 9], fac[N + 9];
const int CP = 78498;
int Prime[CP], tot;
void prework() {
  for (int i = 2; i <= N; i++) {
    if (!primeflag[i]) Prime[tot] = i, fac[i] = tot, tot++;
    for (int j = 0; j < tot; j++) {
      if (i * Prime[j] > N) break;
      primeflag[i * Prime[j]] = 1, fac[i * Prime[j]] = j;
      if (i % Prime[j] == 0) break;
    }
  }
}
stack<int> stk[CP];
int n, a[N + 9];
char op[N + 9];
int pre[N + 9];
long long Ans;
struct segment {
  int l, r, val;
};
stack<segment> g;
int main() {
  prework();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  scanf("%s", op + 1);
  for (int i = 1; i <= n; i++) {
    pre[i] = i;
    if (op[i] == '*')
      while (a[i] != 1) stk[fac[a[i]]].push(i), a[i] /= Prime[fac[a[i]]];
    else if (op[i] == '/')
      while (a[i] != 1) {
        if (stk[fac[a[i]]].empty())
          pre[i] = 0;
        else
          pre[i] = min(pre[i], stk[fac[a[i]]].top()), stk[fac[a[i]]].pop();
        a[i] /= Prime[fac[a[i]]];
      }
  }
  for (int i = n; i >= 1; i--) {
    segment now = (segment){i, i, pre[i]};
    while (!g.empty()) {
      segment nxt = g.top();
      if (nxt.val >= pre[i])
        now.r = nxt.r, g.pop();
      else
        break;
    }
    g.push(now);
    if (now.val == i) Ans += now.r - now.l + 1;
  }
  printf("%lld\n", Ans);
  return 0;
}
