#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxm = 2e5 + 10;
int n;
int ma, mi;
void doit(int now) {
  int l = 1, r = n;
  if (!now) {
    printf("%d ", l);
    l++;
  } else {
    printf("%d ", r);
    r--;
  }
  for (int i = 1; i < n; i++) {
    if (now && mi) {
      printf("%d ", l);
      l++;
      mi--;
      now = 0;
    } else if (!now && ma) {
      printf("%d ", r);
      r--;
      ma--;
      now = 1;
    } else if (now && mi) {
      printf("%d ", l);
      l++;
    } else if (!now && ma) {
      printf("%d ", r);
      r--;
    } else if (now) {
      printf("%d ", r);
      r--;
    } else {
      printf("%d ", l);
      l++;
    }
  }
  printf("\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &ma, &mi);
    if (ma + mi > n - 2 || ma * 2 + 1 > n || mi * 2 + 1 > n ||
        abs(mi - ma) > 1) {
      printf("-1\n");
    } else {
      if (ma > mi) {
        doit(0);
      } else {
        doit(1);
      }
    }
  }
  return 0;
}
