#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, m;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
    if (!m)
      printf("YES\n");
    else {
      if (a + b + c - 3 >= m)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
