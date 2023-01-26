#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }
  long long i, j, k, n, m, c, t, x, y, d;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n + 5];
    for (i = 0; i < n; i++) cin >> a[i];
    vector<pair<long long, long long> > v;
    long long mn = LLONG_MAX, mnind = -1;
    for (i = 0; i < n; i++) {
      mn = LLONG_MAX, mnind = -1;
      for (j = i; j < n; j++) {
        if (a[j] < mn) {
          mn = a[j];
          mnind = j;
        }
      }
      if (i == mnind) continue;
      v.push_back({i + 1, 1 + mnind});
      d = mnind - i;
      long long b[n + 5];
      for (j = i; j <= mnind; j++) {
        c = j - d;
        if (c < i) {
          x = i - c;
          c = mnind - x + 1;
        }
        b[c] = a[j];
      }
      for (j = i; j <= mnind; j++) a[j] = b[j];
    }
    m = v.size();
    cout << m << "\n";
    for (auto z : v) {
      cout << z.first << " " << z.second << " " << z.second - z.first << "\n";
    }
  }
}
