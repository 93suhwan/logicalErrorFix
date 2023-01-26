#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
inline long long read() {
  long long x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x;
}
struct node {
  long long lower_power, k;
} e[maxn];
inline bool cmp(node a, node b) { return a.lower_power < b.lower_power; }
int main() {
  long long _ = read();
  while (_--) {
    long long n = read(), ans = 0;
    for (long long i = 1; i <= n; i++) {
      ans = 0;
      long long k = read();
      for (long long j = 1; j <= k; j++) {
        long long temp = read();
        ans = max(ans, temp - j + 1);
      }
      e[i].lower_power = ans;
      e[i].k = k;
    }
    sort(e + 1, e + 1 + n, cmp);
    ans = e[1].lower_power + 1;
    long long now = ans;
    for (long long i = 2; i <= n; i++) {
      if (e[i].lower_power <= now + e[i - 1].k)
        now += e[i - 1].k;
      else
        now = ans = e[i].lower_power + 1;
    }
    printf("%lld\n", ans);
  }
}
