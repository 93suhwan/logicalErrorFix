#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", max(15ll, (n + 1) / 2 * 5));
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
