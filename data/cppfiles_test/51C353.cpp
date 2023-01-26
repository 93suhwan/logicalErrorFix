#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    printf("%lld %lld\n", -(n - 1), n);
  }
  return 0;
}
