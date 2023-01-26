#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int T, n, mx[N], p[N], ans;
vector<int> v[N];
bool cmp(int x, int y) { return mx[x] < mx[y]; }
void cmax(int &x, int y) { y > x ? x = y : 0; }
void solve() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 1, y; j <= x; j++)
      scanf("%d", &y), v[i].push_back(y), cmax(mx[i], y - j + 2);
  }
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  ans = 0;
  for (int i = 1, dat = 0; i <= n; i++)
    cmax(ans, mx[p[i]] - dat), dat += v[p[i]].size();
  cout << ans << endl;
  for (int i = 1; i <= n; i++) mx[i] = 0;
  for (int i = 1; i <= n; i++) v[i].clear();
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
