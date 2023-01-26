#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, t;
  long long lesspart, morepart;
  long long time1, time2;
  scanf("%d", &t);
  while (t--) {
    time1 = 0;
    time2 = 0;
    scanf("%d%d%d", &a, &b, &c);
    lesspart = a + 2 * b + 3 * c;
    lesspart %= 2;
    printf("%lld\n", lesspart);
  }
}
