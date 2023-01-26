#include <bits/stdc++.h>
using namespace std;
char ch[20];
int x[1000], y[1000], tot;
int main() {
  for (int i = 1; i <= 8; i++) {
    if (i & 1)
      for (int j = 1; j <= 8; j++) x[++tot] = i, y[tot] = j;
    else
      for (int j = 8; j >= 1; j--) x[++tot] = i, y[tot] = j;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int cnt = 0;
    ++cnt;
    printf("%d %d\n", x[cnt], y[cnt]);
    fflush(stdout);
    while (true) {
      ch[4] = 0;
      scanf("%s", ch + 1);
      if (ch[4] == 'e') break;
      ++cnt;
      printf("%d %d\n", x[cnt], y[cnt]);
      fflush(stdout);
    }
  }
  return 0;
}
