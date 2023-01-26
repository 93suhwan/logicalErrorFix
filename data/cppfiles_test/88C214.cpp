#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    vector<long long> a(n);
    for (long long i = 0ll; i != n; i++) scanf("%lld", &a[i]);
    if (n % 2ll == 0ll) {
      printf("YES\n");
      continue;
    }
    bool poss = false;
    for (long long i = 0ll; i != n - 1ll; i++) {
      if (a[i] >= a[i + 1ll]) {
        poss = true;
        break;
      }
    }
    if (poss)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
