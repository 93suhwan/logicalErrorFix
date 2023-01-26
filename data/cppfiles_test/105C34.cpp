#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int n, ans, q[N], x[N], y[N];
struct node {
  int a, b, m, id;
};
vector<node> a[N];
bool cmp(node x, node y) { return x.a < y.a; }
void Work() {
  scanf("%d", &n);
  for (int i = 1, x, y, z; i <= n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    a[x + y - z].push_back((node){x, y, z, i});
    q[i] = x + y - z;
  }
  ans = 0;
  for (int i = 1; i <= n; i++)
    if (a[q[i]].size()) {
      sort(a[q[i]].begin(), a[q[i]].end(), cmp);
      for (int j = 0, px = -1e9; j < (int)a[q[i]].size(); j++) {
        node b = a[q[i]][j];
        if (b.b < q[i] - px) px = min(b.a, q[i]), ans++;
        x[b.id] = b.a - px;
        y[b.id] = b.m - x[b.id];
      }
      a[q[i]].clear();
    }
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) cout << x[i] << " " << y[i] << "\n";
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) Work();
  return 0;
}
