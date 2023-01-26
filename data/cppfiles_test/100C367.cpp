#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
long long a[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long mx = -INF;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    sort(a, a + n);
    long long ans = a[0];
    int p = 0;
    long long s = 0;
    while (p < n) {
      ans = max(ans, a[p] - s);
      s += a[p] - s;
      p++;
    }
    cout << ans << endl;
  }
  return 0;
}
