#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int cor[N][N];
int len[N][N];
int n, k;
bool judge(int x) {
  for (int i = 1; i <= n; i++) {
    int c = cor[i - 1][i] + 1;
    for (int j = i + 1; j <= n; j++) {
      if (c == cor[i - 1][i]) c++;
      if (c > x) c = 1;
      cor[i][j] = c;
      c++;
      if (c > x) c = 1;
    }
  }
  memset(len, 0, sizeof(len));
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      len[j][cor[i][j]] = max(len[j][cor[i][j]], len[i][cor[i][j]] + 1);
      if (len[j][cor[i][j]] >= k) return 0;
    }
  }
  return 1;
}
void pr(int x) {
  for (int i = 1; i <= n; i++) {
    int c = cor[i - 1][i] + 1;
    for (int j = i + 1; j <= n; j++) {
      if (c == cor[i - 1][i]) c++;
      if (c > x) c = 1;
      printf("%d ", c);
      c++;
      if (c > x) c = 1;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  int l = 2, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (judge(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  pr(l);
  return 0;
}
