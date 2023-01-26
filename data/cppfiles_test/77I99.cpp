#include <bits/stdc++.h>
int toAnd[4] = {1, 2, 4, 8};
int wall[1005][1005][2] = {0};
bool searched[1005][1005] = {0};
int curedge[1005] = {0};
int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int t;
      scanf("%d", &t);
      wall[i][j][0] = t & toAnd[1];
      wall[i][j][1] = t & toAnd[2];
    }
  }
  int s[3 * 1005][2] = {0};
  int ans[1005 * 1005] = {0};
  int front = 0, back = 0;
  int size = 0, cnt = 0, all = n * m, room = 0;
  front = 1;
  searched[0][0] = true;
  while (cnt < all) {
    int r = 0, c = 0;
    if (front == back) {
      ans[room++] = size;
      size = 0;
      for (r = 0; r < n && curedge[r] >= m; r++)
        ;
      c = curedge[r];
      for (; searched[r][curedge[r]] == false; curedge[r]++)
        ;
    } else {
      r = s[back][0];
      c = s[back][1];
      back = (back + 1) % (3 * 1005);
    }
    size++;
    cnt++;
    if (c < n && !wall[r][c][0]) {
      if (searched[r][c + 1] == false) {
        s[front][0] = r;
        s[front][1] = c + 1;
        searched[r][c + 1] = true;
        front = (front + 1) % (3 * 1005);
        if (curedge[r] < c + 1)
          for (; searched[r][curedge[r]] == false; curedge[r]++)
            ;
      }
    }
    if (r < m && !wall[r][c][1]) {
      if (searched[r + 1][c] == false) {
        s[front][0] = r + 1;
        s[front][1] = c;
        searched[r + 1][c] = true;
        front = (front + 1) % (3 * 1005);
        if (curedge[r + 1] < c)
          for (; searched[r + 1][curedge[r + 1]] == false; curedge[r + 1]++)
            ;
      }
    }
    cnt++;
  }
  qsort(ans, room, sizeof(int), cmp);
  for (int i = 0; i < room; i++) printf("%d ", ans[i]);
  return 0;
}
