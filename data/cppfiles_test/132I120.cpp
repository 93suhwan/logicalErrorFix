#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[5], cnt, f;
void dfs(int idx, int val) {
  if (f) return;
  if (cnt == 3) {
    if (!val) {
      printf("%d %d %d", b[0], b[1], b[2]);
      f = 1;
    }
    return;
  }
  for (int i = idx; i >= 1; i--) {
    if (val - a[i] >= 0) {
      b[cnt++] = a[i];
      dfs(i, val - a[i]);
      cnt--;
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    cnt = f = 0;
    for (int i = 1; i <= 7; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + 7);
    dfs(6, a[7]);
    puts("");
  }
}
