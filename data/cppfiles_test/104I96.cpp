#include <bits/stdc++.h>
using namespace std;
long long a[1000005], b[1000005], first[1000005], second[1000005];
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
      sa += a[i];
      sb += b[i];
    }
    for (int i = 1; i <= n; ++i) {
      first[i] = second[i] = 0;
      if (sa < sb)
        second[i] = min(sb - sa, m);
      else
        first[i] = min(sa - sb, m);
      int u = m - second[i] - first[i];
      second[i] += u / 2;
      first[i] += u - u / 2;
      sb -= second[i];
      sa -= first[i];
    }
    cout << abs(sa - sb) << endl;
    for (int i = 1; i <= n; ++i) cout << first[i] << " " << second[i] << endl;
  }
}
