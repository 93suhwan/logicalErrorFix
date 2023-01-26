#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  int t = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    printf("%lld %lld\n", 1 - n, n);
  }
  return 0;
}
