#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  return read();
}
signed main() {
  int A = query(1, 1), B = query(1, 1000000000), C = query(1000000000, 1),
      D = query(1000000000, 1000000000);
  int res = 1;
  for (int i = 29; i >= 0; i--) {
    int cur = query(res + (1 << i), 1);
    if (cur == A - (1 << i)) res += 1 << i;
  }
  int x1 = res, y1 = A - (x1 - 1) + 1,
      x2 = 1000000000 - (C - (1000000000 - y1)),
      y2 = 1000000000 - (D - (1000000000 - x2));
  printf("! %d %d %d %d\n", x1, y1, x2, y2);
  return 0;
}
