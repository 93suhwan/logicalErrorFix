#include <bits/stdc++.h>
using namespace std;
const int N = 55;
char a[N];
int flag[N];
vector<int> v[15];
void solve() {
  int q = 0, i, n;
  memset(flag, 0, sizeof(flag));
  scanf("%d%s", &n, a + 1);
  for (i = 1; i <= n; ++i) {
    if (a[i] == '1' || a[i] == '4' || a[i] == '6' || a[i] == '8' ||
        a[i] == '9') {
      printf("1\n");
      printf("%c\n", a[i]);
      return;
    }
    flag[a[i] - '0']++;
    if (a[i] == '5' && (flag[3] || flag[2] || flag[7])) {
      q = 1;
    } else if (a[i] == '7' && (flag[2] || flag[5])) {
      if (flag[2]) {
        q = 2;
      } else {
        q = 5;
      }
    } else if (a[i] == '2' && i > 1) {
      q = 3;
    }
  }
  printf("2\n");
  if (q == 1) {
    for (i = 1; i <= 9; ++i) {
      if (i == 5) continue;
      if (flag[i]) {
        printf("%d%d\n", i, 5);
        return;
      }
    }
  } else if (q == 3) {
    printf("%c%d\n", a[1], 2);
  } else if (q > 0) {
    printf("%d%d\n", q, 7);
  }
  for (i = 1; i <= 9; ++i) {
    if (flag[i] > 1) {
      printf("%d%d\n", i, i);
      return;
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
