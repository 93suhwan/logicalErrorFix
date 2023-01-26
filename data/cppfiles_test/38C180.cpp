#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    unsigned long long n;
    scanf("%lld", &n);
    if (n <= 6)
      printf("15\n");
    else
      printf("%lld\n", (n + 1) / 2 * 5);
  }
  return 0;
}
