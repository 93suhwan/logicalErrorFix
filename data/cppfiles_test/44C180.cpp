#include <bits/stdc++.h>
using namespace std;
int a[2000000];
int b[2000000];
int cmp(int a, int b) { return a > b; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (abs(n - m) % 2)
      printf("-1\n");
    else {
      if (n == 0 && m == 0)
        printf("0\n");
      else if (n == m)
        printf("1\n");
      else
        printf("2\n");
    }
  }
  return 0;
}
