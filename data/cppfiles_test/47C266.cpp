#include <bits/stdc++.h>
using namespace std;
int a1[1000010], a2[1000010];
bool cmp(int a, int b) { return a > b; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n, k, x;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int l1 = 0, l2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      if (x < 0)
        a1[l1++] = abs(x);
      else
        a2[l2++] = abs(x);
    }
    sort(a1, a1 + l1, cmp);
    sort(a2, a2 + l2, cmp);
    long long ans = 0;
    for (int i = 0; i < l1; i += k) ans += a1[i] * 2;
    for (int i = 0; i < l2; i += k) ans += a2[i] * 2;
    int maxx = 0;
    if (l1 > 0) maxx = max(maxx, a1[0]);
    if (l2 > 0) maxx = max(maxx, a2[0]);
    ans -= maxx;
    cout << ans << '\n';
  }
  return 0;
}
