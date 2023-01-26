#include <bits/stdc++.h>
using namespace std;
int T;
long long s, n, k;
int main() {
  scanf("%d", &T);
  while (T--)
    scanf("%lld%lld%lld", &s, &n, &k),
        puts((s == k || (n << 1 | 1) > s + k) && s >= k ? "YES" : "NO");
  return 0;
}
