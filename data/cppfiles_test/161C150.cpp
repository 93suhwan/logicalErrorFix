#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, l[1005], r[1005], g, a[1005];
bool b[1005];
set<pair<long long, long long>> s;
bool f, ff;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int j = 0;
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
      if (l[i] == r[i])
        a[i] = l[i], b[l[i]] = 1;
      else {
        s.insert({r[i] - l[i] + 1, i});
        j++;
      }
    }
    auto i = s.begin();
    while (i != s.end()) {
      f = 0, ff = 0;
      for (int k = l[i->second]; k <= r[i->second]; k++) {
        if (!b[k] && f) {
          ff = 1;
          break;
        } else if (!b[k])
          g = k, f = 1;
      }
      if (f && !ff) {
        b[g] = 1;
        a[i->second] = g;
        s.erase(i);
        i = s.begin();
      } else
        i++;
    }
    for (int i = 0; i < n; i++) {
      cout << l[i] << " " << r[i] << " " << a[i] << endl;
      b[i] = 0;
    }
    b[n] = 0;
    s.clear();
  }
  return 0;
}
