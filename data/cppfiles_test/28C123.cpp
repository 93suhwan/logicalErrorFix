#include <bits/stdc++.h>
using namespace std;
int T, n, m, p[300010], nxt[300010], v[300010];
vector<int> f[300010], d;
bool check(int k) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) nxt[i] = p[(i + k - 1) % n + 1], v[i] = 0;
  for (int i = 1; i <= n; i++)
    if (!v[i]) {
      cnt++;
      int x = i;
      while (nxt[x] != i) v[x] = 1, x = nxt[x];
      v[x] = 1;
    }
  return cnt >= n - m;
}
void init() {
  d.clear();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) f[i].clear();
  for (int i = 1; i <= n; i++)
    scanf("%d", &p[i]), f[(i + n - p[i]) % n].push_back(i);
  for (int i = 0; i < n; i++)
    if (f[i].size() >= n - 2 * m && check(i)) d.push_back(i);
  printf("%d", (int)d.size());
  for (auto i : d) printf(" %d", i);
  printf("\n");
}
int main() {
  scanf("%d", &T);
  while (T--) init();
}
