#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node {
  int x, id;
} a[N * 2], b[N], g[N * 2];
long long Pre[2 * N], f[2 * N], num[N * 2];
set<int> s;
bool cmp(node a, node b) { return a.x < b.x; }
long long calc(int l, int r) { return Pre[r] - Pre[r - num[r] + num[l - 1]]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, cnt = 1;
  long long suma = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    a[i].id = 1;
    suma += a[i].x;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i + n].x;
    a[i + n].id = 0;
  }
  sort(a + 1, a + 1 + n + m, cmp);
  for (int i = 1; i <= n + m; i++) {
    Pre[i] = Pre[i - 1] + a[i].x;
    num[i] = num[i - 1] + a[i].id;
  }
  for (int i = 1; i <= k; i++) {
    cin >> b[i].x;
    b[i].id = i;
  }
  sort(b + 1, b + 1 + k, cmp);
  for (int i = 1; i < n + m; i++) {
    g[i].x = a[i + 1].x - a[i].x;
    g[i].id = i;
  }
  sort(g + 1, g + n + m, cmp);
  for (int i = 1; i <= n + m + 1; i++) s.insert(i);
  for (int i = 1; i <= k; i++) {
    while (cnt < n + m && g[cnt].x <= b[i].x) {
      auto it = s.upper_bound(g[cnt].id);
      auto l = it, r = it;
      l--, r++;
      suma = suma + calc(*l, *r - 1) - calc(*l, *it - 1) - calc(*it, *r - 1);
      s.erase(it);
      cnt++;
    }
    f[b[i].id] = suma;
  }
  for (int i = 1; i <= k; i++) cout << f[i] << endl;
}
