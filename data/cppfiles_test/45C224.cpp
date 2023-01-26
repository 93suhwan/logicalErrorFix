#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 3;
const long long mod = 1e9 + 7;
int n, a;
vector<int> b;
void solve() {
  b.clear();
  long long ans = 1e18;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a);
    if (a % 2) b.push_back(i);
  }
  if ((n % 2 == 0 && b.size() != n / 2) ||
      (n % 2 == 1 && (b.size() != n / 2 && b.size() != n / 2 + 1)))
    ans = -1;
  else {
    int t = 0;
    if ((n % 2 == 1 && b.size() == n / 2 + 1) || (n % 2 == 0)) {
      for (int i = 0, j = 1; i < b.size(); ++i, j += 2) {
        t += abs(b[i] - j);
      }
      ans = min(ans, 1LL * t);
    }
    t = 0;
    if ((n % 2 == 1 && b.size() == n / 2) || (n % 2 == 0)) {
      for (int i = 0, j = 2; i < b.size(); ++i, j += 2) {
        t += abs(b[i] - j);
      }
      ans = min(ans, 1LL * t);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
