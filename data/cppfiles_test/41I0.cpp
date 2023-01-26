#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int e[N][N];
int n, k, mxdeep = 0;
void paint(int l, int r, int deep) {
  if (l == r) return;
  mxdeep = max(mxdeep, deep);
  int sz = max(1, (r - l) / k + 1);
  for (int id = l; id <= r; id += sz) {
    for (int i = id; i < id + sz; i++) {
      for (int j = id + sz; j <= r; j++) {
        e[i][j] = deep;
      }
    }
    paint(id, min(n, id + sz - 1), deep + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  paint(1, n, 1);
  printf("%d\n", mxdeep);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      printf("%d ", e[i][j]);
    }
  }
  return 0;
}
