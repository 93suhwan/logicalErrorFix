#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, x, cnt;
int res[N], st[N];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first >= b.first; }
void solve() {
  scanf("%d", &n);
  cnt = 0;
  memset(res, 0, sizeof res);
  memset(st, 0, sizeof st);
  pair<int, int> a[N], b[N];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    a[i] = {x, i};
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    b[i] = {x, i};
  }
  sort(a + 1, a + n + 1, cmp);
  sort(b + 1, b + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    if (!st[a[i].second]) cnt++;
    st[a[i].second]++;
    if (!st[a[i].second]) cnt--;
    if (!st[b[i].second]) cnt++;
    st[b[i].second]--;
    if (!st[b[i].second]) cnt--;
    res[b[i].second] = 1, res[a[i].second] = 1;
    if (cnt == 0) break;
  }
  for (int i = 1; i <= n; i++) printf("%d", res[i]);
  puts(" ");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
