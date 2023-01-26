#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
void solve() {
  long long n;
  scanf("%lld", &n);
  long long ans = (n * (n - 1) * (n - 2)) / 6;
  vector<int> c(n + 1);
  vector<int> d(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    c[a[i]]++;
    d[b[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    ans -= (long long)(c[a[i]] - 1) * (d[b[i]] - 1);
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
