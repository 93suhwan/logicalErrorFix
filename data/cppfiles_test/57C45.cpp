#include <bits/stdc++.h>
using namespace std;
int T;
long long s, n, k, tt, fi;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &s, &n, &k);
    if (k >= s) {
      puts(k > s ? "NO" : "YES");
      continue;
    }
    fi = s / k, tt = (fi >> 1) * k + (fi & 1 ? k - 1 : s % k);
    puts(tt >= n ? "NO" : "YES");
  }
  return 0;
}
