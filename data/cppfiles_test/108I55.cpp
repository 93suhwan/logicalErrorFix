#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, x;
int res[N];
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first >= b.first; }
void solve() {
  scanf("%d", &n);
  memset(res, 0, sizeof res);
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
  int idx1 = a[1].second, idx2 = b[1].second, idx3;
  if (idx1 == idx2)
    res[idx1] = 1;
  else {
    for (int i = 1; i <= n; i++) {
      if (b[i].second == idx1) {
        idx3 = i;
        break;
      }
    }
    for (int i = 1; i <= idx3; i++) res[b[i].second] = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i].second == idx2) {
        idx3 = i;
        break;
      }
    }
    for (int i = 1; i <= idx3; i++) res[a[i].second] = 1;
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
