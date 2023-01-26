#include <bits/stdc++.h>
#pragma GCC optimize( \
    "Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
using namespace std;
const int N = 2e5 + 5, M = 2 * N + 5;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sum = 0, len = 1;
    while (sum + len < n) {
      sum += len;
      len += 2;
    }
    int num = len / 2;
    if (n - sum <= num)
      printf("%d %d\n", n - sum, num + 1);
    else
      printf("%d %d\n", num + 1, 2 * (num + 1) - (n - sum));
  }
}
