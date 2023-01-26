#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  long long l, r, s;
  while (t--) {
    scanf("%lld%lld", &l, &r);
    s = r / 2;
    if (s >= l && r % 2 == 1)
      printf("%lld\n", s);
    else if (s >= l && r % 2 == 0)
      printf("%lld\n", s - 1);
    else
      printf("%lld\n", r % l);
  }
  return 0;
}
