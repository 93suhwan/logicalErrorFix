#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if ((a + b) % 2)
      puts("-1");
    else if (a == b && a)
      puts("1");
    else if (a == b && !a)
      puts("0");
    else
      puts("2");
  }
  return 0;
}
