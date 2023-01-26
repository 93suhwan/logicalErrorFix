#include <bits/stdc++.h>
int toAnd[4] = {1, 2, 4, 8};
int connect[1005][1005] = {0};
bool searched[1005][1005] = {0};
int curedge[1005] = {0};
int ans[1005 * 1005] = {0};
int s[1005 * 1005][2] = {0};
int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &connect[i][j]);
    }
  }
  int front = 0, back = 0;
  int size = 0, cnt = 0, all = n * m, room = 0;
  front = 1;
  searched[0][0] = true;
  curedge[0] = 1;
  while (cnt < all) {
    int r = 0, c = 0;
    if (front == back) {
      ans[room++] = size;
      size = 0;
      for (r = 0; r < n && curedge[r] >= m; r++)
        ;
      c = curedge[r];
      searched[r][c] = true;
      if (curedge[r] <= c)
        for (; searched[r][curedge[r]]; curedge[r]++)
          ;
    } else {
      r = s[back][0];
      c = s[back][1];
      back = back + 1;
    }
    size++;
    if (r > 0 && !(connect[r][c] & 8)) {
      if (searched[r - 1][c] == false) {
        s[front][0] = r - 1;
        s[front][1] = c;
        searched[r - 1][c] = true;
        front++;
        if (curedge[r - 1] <= c)
          for (; searched[r - 1][curedge[r - 1]]; curedge[r - 1]++)
            ;
      }
    }
    if (c < m - 1 && !(connect[r][c] & 4)) {
      if (searched[r][c + 1] == false) {
        s[front][0] = r;
        s[front][1] = c + 1;
        searched[r][c + 1] = true;
        front++;
        if (curedge[r] <= c + 1)
          for (; searched[r][curedge[r]]; curedge[r]++)
            ;
      }
    }
    if (r < n - 1 && !(connect[r][c] & 2)) {
      if (searched[r + 1][c] == false) {
        s[front][0] = r + 1;
        s[front][1] = c;
        searched[r + 1][c] = true;
        front++;
        if (curedge[r + 1] <= c)
          for (; searched[r + 1][curedge[r + 1]]; curedge[r + 1]++)
            ;
      }
    }
    if (c > 0 && !(connect[r][c] & 1)) {
      if (searched[r][c - 1] == false) {
        s[front][0] = r;
        s[front][1] = c - 1;
        searched[r][c - 1] = true;
        front++;
        if (curedge[r] <= c - 1)
          for (; searched[r][curedge[r]]; curedge[r]++)
            ;
      }
    }
    cnt++;
  }
  ans[room++] = size;
  qsort(ans, room, sizeof(int), cmp);
  for (int i = 0; i < room; i++) printf("%d ", ans[i]);
  return 0;
}
