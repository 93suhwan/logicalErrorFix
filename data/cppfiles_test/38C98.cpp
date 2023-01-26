#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    if (n <= 6)
      printf("15\n");
    else if (n % 2 == 0)
      printf("%lld\n", (long long)(n * 5 / 2));
    else
      printf("%lld\n", (long long)((n - 5) * 5 / 2 + 15));
  }
  return 0;
}
