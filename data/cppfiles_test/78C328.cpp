#include <bits/stdc++.h>
using namespace std;
int T, l, r;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &l, &r);
    if (r < 2 * l)
      printf("%d\n", r - l);
    else
      printf("%d\n", r - 1 >> 1);
  }
  return 0;
}
