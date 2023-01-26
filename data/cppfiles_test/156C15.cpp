#include <bits/stdc++.h>
using namespace std;
const int maxn = 300020;
const double E = 1e-9;
const double INF = 1e9 + 7;
long long ar[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int tt = 1; tt <= n; tt++) {
    long long a, k;
    scanf("%lld %lld", &a, &k);
    long long tot = 0;
    for (int i = 1; i <= a; i++) scanf("%lld", &ar[i]), tot += ar[i];
    sort(ar + 1, ar + 1 + a);
    long long h = k / a;
    long long ans = 0, t = 0;
    if (ar[1] > h) {
      ans += ar[1] - h;
      tot -= ar[1] - h;
      ar[1] = h;
    }
    tot -= k;
    long long mini = 1e18;
    if (tot <= 0) {
      printf("%lld\n", ans);
      continue;
    }
    for (int i = a; i >= 1; i--) {
      ans++;
      tot -= ar[i] - ar[1];
      if (tot <= 0) {
        mini = min(mini, ans);
        break;
      }
      mini = min(mini, ans + (tot - 1) / (a - i + 2) + 1);
    }
    printf("%lld\n", mini);
  }
}
