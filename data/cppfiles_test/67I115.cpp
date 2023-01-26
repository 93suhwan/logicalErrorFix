#include <bits/stdc++.h>
using namespace std;
long long C3(int x) { return 1LL * x * (x - 1) * (x - 2) / 6; }
long long C2(int x) { return 1LL * x * (x - 1) / 2; }
int main() {
  int n, P;
  double PP;
  scanf("%d%lf", &n, &PP);
  P = int(PP * 10000 + 0.5);
  for (int x = 0; x <= n; x++) {
    long long up = C3(x) + C2(x) * (n - x);
    if (up * 10000 >= P * C3(n)) {
      printf("%d\n", x);
      return 0;
    }
  }
  assert(false);
}
