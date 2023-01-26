#include <bits/stdc++.h>
using namespace std;
int T, c, d;
int Abs(int x) { return x >= 0 ? x : -x; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &c, &d);
    if (c == d) {
      if (c)
        printf("1\n");
      else
        printf("0\n");
    } else {
      if (Abs(c - d) & 1)
        printf("-1\n");
      else
        printf("2\n");
    }
  }
}
