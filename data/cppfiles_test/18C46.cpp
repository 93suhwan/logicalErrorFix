#include <bits/stdc++.h>
using namespace std;
struct P {
  int p, s;
};
int t, n, d, a[1000010];
void solve(void) {
  queue<P> q;
  int ans = 0;
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (!a[i]) q.push((P){i, 0});
  }
  if (q.size() == n) {
    puts("0");
    return;
  }
  while (!q.empty()) {
    P now = q.front();
    q.pop();
    ans = max(ans, now.s);
    if (a[(now.p + d) % n]) {
      int nex = (now.p + d) % n;
      a[nex] = 0;
      q.push((P){nex, now.s + 1});
    }
  }
  for (int i = 0; i < n; i++)
    if (a[i]) {
      puts("-1");
      return;
    }
  printf("%d\n", ans);
  return;
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
