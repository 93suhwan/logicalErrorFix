#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Dat {
  int f, x, y;
  Dat() {}
  Dat(int f, int x, int y) {
    this->f = f;
    this->x = x;
    this->y = y;
  }
};
Dat dat[N];
int fa[N];
int find(int x);
int ans[N];
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < N; i++) {
    fa[i] = i;
  }
  for (int i = 0; i < q; i++) {
    int f, x, y;
    scanf("%d%d", &f, &x);
    if (f == 2) {
      scanf("%d", &y);
    }
    dat[i] = Dat(f, x, y);
  }
  int cnt = 0;
  for (int i = q - 1; i >= 0; i--) {
    if (dat[i].f == 1) {
      ans[cnt++] = find(dat[i].x);
    } else {
      fa[(dat[i].x)] = find(dat[i].y);
    }
  }
  for (int i = cnt - 1; i >= 0; i--) {
    printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
  }
  return 0;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
