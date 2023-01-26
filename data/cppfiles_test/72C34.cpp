#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 1e6 + 10;
const int inf = 1e9;
int c[2];
int a[2][2];
int ask(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  assert(res != -1);
  return res;
}
int main() {
  c[0] = 1, c[1] = inf;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a[i][j] = ask(c[i], c[j]);
    }
  }
  int &t = a[0][0];
  int L = 2, R = inf;
  while (R - L > 1) {
    int mid = L + R >> 1;
    int dis = ask(mid, 1);
    if (t - dis == mid - 1)
      L = mid;
    else
      R = mid;
  }
  int xmin = L, ymin = t - L + 2;
  int ymax = xmin - 1 + inf - a[0][1];
  int xmax = inf - 1 + ymin - a[1][0];
  printf("! %d %d %d %d\n", xmin, ymin, xmax, ymax);
  fflush(stdout);
  return 0;
}
