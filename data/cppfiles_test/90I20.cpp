#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long x, y, n;
int t;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &x, &y);
    long long a = x * y / gcd(x, y);
    printf("%lld\n", a);
  }
  return 0;
}
