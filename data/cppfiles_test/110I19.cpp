#include <bits/stdc++.h>
using namespace std;
const int MX = 100100;
int n, n3, num, i, best, allx[MX], ally[MX], x[MX], y[MX], z[MX], k[MX],
    c[270270][3], order[7][7], col[7];
bool u[7];
void init(int i, int L, int R) {
  for (int j = 0; j < 3; j++) c[i][j] = 0;
  if (L == R) return;
  int mid = (L + R) / 2;
  init(i * 2, L, mid);
  init(i * 2 + 1, mid + 1, R);
}
void add(int i, int L, int R, int pos, int col) {
  while (L != R) {
    ++c[i][col];
    int mid = (L + R) / 2;
    if (pos <= mid) {
      R = mid;
      i = i * 2;
    } else {
      L = mid + 1;
      i = i * 2 + 1;
    }
  }
  ++c[i][col];
}
int fnd(int i, int L, int R, int x, int y, int lft, int rgh) {
  if (L == R) return max(min(lft + c[i][x], rgh), min(lft, rgh + c[i][y]));
  int mid = (L + R) / 2;
  int lv = lft + c[i * 2][x];
  int rv = rgh + c[i * 2 + 1][y];
  if (lv == rv) return rv;
  if (lv > rv) return fnd(i * 2, L, mid, x, y, lft, rgh + rv);
  return fnd(i * 2 + 1, mid + 1, R, x, y, lft + lv, rgh);
}
void rot() {
  for (int i = 0; i < n; i++) {
    int tmp = y[i];
    y[i] = n - x[i] + 1;
    x[i] = tmp;
  }
}
bool cmp(int i, int j) { return x[i] < x[j]; }
void rec(int l) {
  if (l == 3) {
    for (int i = 0; i < 3; i++) order[num][i] = col[i];
    num++;
    return;
  }
  for (int i = 0; i < 3; i++)
    if (!u[i]) {
      u[i] = true;
      col[l] = i;
      rec(l + 1);
      u[i] = false;
    }
}
void solve() {
  for (int j = 0; j < 4; j++) {
    sort(k, k + n, cmp);
    init(1, 1, n);
    for (int i = 0; i < n; i++) {
      add(1, 1, n, y[k[i]], z[k[i]]);
      if (i + 1 == n || x[k[i]] != x[k[i + 1]])
        for (int idx = 0; idx < num; idx++) {
          if (n3 - c[1][order[idx][0]] > best)
            best = max(best,
                       min(n3 - c[1][order[idx][0]],
                           fnd(1, 1, n, order[idx][1], order[idx][2], 0, 0)));
        }
    }
    if (j < 3) rot();
  }
}
int main() {
  scanf("%d", &n);
  n3 = n / 3;
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &y[i], &z[i]);
    --z[i];
    k[i] = i;
    allx[i] = x[i];
    ally[i] = y[i];
  }
  sort(allx, allx + n);
  sort(ally, ally + n);
  for (i = 0; i < n; i++) {
    x[i] = lower_bound(allx, allx + n, x[i]) - allx + 1;
    y[i] = lower_bound(ally, ally + n, y[i]) - ally + 1;
  }
  rec(0);
  solve();
  printf("%d\n", best * 3);
  return 0;
}
