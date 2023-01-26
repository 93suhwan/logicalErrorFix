#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
bool vis[maxn];
struct node {
  int l, r;
  int res;
} p[maxn];
bool cmp(node a, node b) {
  if (a.r - a.l == b.r - b.l)
    return a.l < b.l;
  else
    return a.r - a.l < b.r - b.l;
}
void solve() {
  for (int i = 1; i <= 1000; i++) vis[i] = false;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i].l >> p[i].r;
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    int l = p[i].l, r = p[i].r;
    if (l == r) {
      p[i].res = l;
      vis[l] = true;
    } else {
      for (int t = l; t <= r; t++) {
        if (vis[t] == false) {
          p[i].res = t;
          vis[t] = true;
          break;
        }
      }
    }
    cout << l << " " << r << " " << p[i].res << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
