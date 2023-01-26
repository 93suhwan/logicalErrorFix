#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
void solve() {
  long long n, m, r1, c1, r2, c2;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &r1);
  scanf("%lld", &c1);
  scanf("%lld", &r2);
  scanf("%lld", &c2);
  int ans1, ans2;
  if (r1 <= r2)
    ans1 = r2 - r1;
  else
    ans1 = 2 * n - r2 - r1;
  if (c1 <= c2)
    ans2 = c2 - c1;
  else
    ans2 = 2 * m - c1 - c2;
  cout << ans1 << ":" << ans2 << " ";
  cout << min(ans1, ans2) << endl;
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    solve();
  }
}
