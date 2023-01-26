#include <bits/stdc++.h>
using namespace std;
void test() {
  long long n;
  scanf("%lld", &n);
  long long l = 2, r = n;
  if (l > r) swap(l, r);
  printf("%lld %lld\n", l, r);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) test();
}
