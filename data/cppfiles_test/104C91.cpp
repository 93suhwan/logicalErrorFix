#include <bits/stdc++.h>
using namespace std;
long long a[1000005], b[1000005], first[1000005], second[1000005], a1[1000005],
    b1[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    long long n, m;
    cin >> n >> m;
    long long sa = 0, sb = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i] >> b[i];
      a1[i] = a[i];
      b1[i] = b[i];
    }
    for (int i = 1; i <= n; ++i) {
      first[i] = min(m, a[i]);
      second[i] = m - first[i];
      a[i] -= first[i];
      b[i] -= second[i];
      sa += a[i];
      sb += b[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (sa > sb) {
        long long o = min({a[i], b1[i] - b[i], (sa - sb) / 2});
        a[i] -= o;
        first[i] += o;
        b[i] += o;
        second[i] -= o;
        sa -= o;
        sb += o;
      } else if (sa < sb) {
        long long o = min({b[i], a1[i] - a[i], (sb - sa) / 2});
        a[i] += o;
        first[i] -= o;
        b[i] -= o;
        second[i] += o;
        sa += o;
        sb -= o;
      }
    }
    cout << abs(sa - sb) << endl;
    for (int i = 1; i <= n; ++i) cout << first[i] << " " << second[i] << endl;
  }
}
