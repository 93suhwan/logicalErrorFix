#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1e3 + 7;
int T, n, ans[N];
int rd() { return (1ll * rand() * rand() + rand()) % INT_MAX; }
int rnd(int l, int r) { return rd() % (r - l + 1) + l; }
map<vector<int>, int> vis;
int query(int x, int y, int z) {
  if (x > z) swap(x, z);
  if (x > y) swap(x, y);
  if (y > z) swap(y, z);
  if (vis.count({x, y, z})) return vis[{x, y, z}];
  printf("? %d %d %d\n", x, y, z);
  fflush(stdout);
  int &ret = vis[{x, y, z}];
  scanf("%d", &ret);
  return ret;
}
int main() {
  srand(time(NULL));
  scanf("%d", &T);
  while (T--) {
    vis.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) ans[i] = -1;
    int X = -1, Y = -1, last = -1;
    for (int i = 0; i < n; i++) {
      int x = i, y = (i + 1) % n, z = (i + 2) % n;
      int k = query(x + 1, y + 1, z + 1);
      if (last != -1) {
        if (last != k) {
          X = x + 1, Y = y + 1;
          ans[(x - 1 + n) % n + 1] = last;
          ans[z + 1] = k;
          ans[x + 1] = query(z + 1, (x - 1 + n) % n + 1, x + 1);
          ans[y + 1] = ans[x + 1] ^ 1;
          break;
        }
      }
      last = k;
    }
    if (X == -1) {
      X = 1, Y = 2;
      ans[3] = query(1, 2, 3);
      ans[n] = query(n, 1, 2);
      ans[1] = query(3, n, 1);
      ans[2] = ans[1] ^ 1;
    }
    for (int i = 1; i <= n; i++)
      if (ans[i] == -1) ans[i] = query(i, X, Y);
    int k = 0;
    for (int i = 1; i <= n; i++)
      if (!ans[i]) k++;
    printf("! %d ", k);
    for (int i = 1; i <= n; i++)
      if (!ans[i]) printf("%d ", i);
    puts("");
    fflush(stdout);
  }
}
