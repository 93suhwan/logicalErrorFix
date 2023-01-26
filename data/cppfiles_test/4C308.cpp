#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int in[N], out[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    if (n == 5)
      printf("2 4\n");
    else
      printf("%d %d\n", 2, n / 2);
  }
  return 0;
}
