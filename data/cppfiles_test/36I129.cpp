#include <bits/stdc++.h>
using namespace std;
int T, n;
int main() {
  srand(114514);
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) putchar('a' + rand() % 26);
    putchar('\n');
  }
  getchar();
  getchar();
  return 0;
}
