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
    int p = 0;
    long long m = 0;
    for (int i = 0; i < n - 1 && a[i] < 0; i++) {
      if (i > 0) m += a[i - 1] - a[i];
      p++;
    }
    if (p - 1 >= 0) {
      m += a[p - 1];
    }
    long long s = m;
    while (p < n - 1 && a[p] - s < mx - s - a[p]) {
      s += a[p] - s;
      p++;
    }
    cout << a[p] - s << endl;
  }
  return 0;
}
