#include <bits/stdc++.h>
using namespace std;
int res[105];
int main() {
  int n;
  scanf("%d", &n);
  int idx = 0;
  for (int i = 1; i < n; i++) {
    printf("? ");
    for (int j = 1; j < n; j++) printf("%d ", n);
    printf("%d\n", i);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x) {
      idx = n + 1 - i;
      break;
    }
  }
  if (idx == 0) idx = 1;
  res[n] = idx;
  for (int i = 1; i <= n; i++) {
    if (i == idx) continue;
    printf("? ");
    int p = n + 1 - i;
    for (int j = 1; j < n; j++) printf("%d ", p);
    printf("%d\n", n + 1 - idx);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    res[x] = i;
  }
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d ", res[i]);
  return 0;
}
