#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x;
    scanf("%lld", &x);
    int di = x / 3;
    if (x % 3 == 2) {
      di++;
    } else if (x % 3 == 1) {
    }
    printf("%d %d\n", di, x - 2 * di);
  }
}
