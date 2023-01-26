#include <bits/stdc++.h>
using namespace std;
long long t, a, b;
int main() {
  cin >> t;
  while (t--) {
    scanf("%lld%lld", &a, &b);
    if (a == b) {
      if (a == 0)
        printf("0\n");
      else
        printf("1\n");
    } else {
      if ((a + b) % 2 == 0)
        printf("2\n");
      else
        printf("-1\n");
    }
  }
}
