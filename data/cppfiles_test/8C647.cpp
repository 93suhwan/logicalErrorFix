#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int d = (n + 1) % 3 - 1;
    int c2 = (n - d) / 3;
    int c1 = c2 + d;
    printf("%d %d\n", c1, c2);
  }
}
