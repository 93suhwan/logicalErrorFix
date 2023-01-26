#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5;
long long t, l1, l2, l3;
bool check(long long x, long long y, long long z) {
  if (x + y == z || x + z == y || y + z == x) return 1;
  if ((x == y && z % 2 == 0) || (x == z && y % 2 == 0) ||
      (y == z && x % 2 == 0))
    return 1;
  return 0;
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld %lld", &l1, &l2, &l3);
    if (check(l1, l2, l3))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
