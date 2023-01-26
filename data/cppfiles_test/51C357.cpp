#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main() {
  cin >> t;
  while (t--) {
    scanf("%lld", &n);
    printf("%lld %lld\n", -n + 1, n);
  }
  return 0;
}
