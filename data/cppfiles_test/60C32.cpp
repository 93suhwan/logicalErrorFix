#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int maxblock = sqrt(maxn) + 10;
const double eps = 1e-7;
const long long INF = 1e16;
int n;
int a[maxn];
map<int, int> ma;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ma.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    long long g = gcd(sum, n);
    long long fenzi = sum / g;
    long long fenmu = n / g;
    if (fenmu > 2) {
      printf("0\n");
      continue;
    }
    long long res = 0;
    long long target = fenzi * (2 / fenmu);
    for (int i = 1; i <= n; i++) {
      res += ma[target - a[i]];
      ma[a[i]]++;
    }
    printf("%lld\n", res);
  }
  return 0;
}
