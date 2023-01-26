#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 10;
long long t, n;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    long long l = -1 * n + 1;
    printf("%lld %lld\n", l, n);
  }
}
