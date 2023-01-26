#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, x, y, ans, q, o, l, r;
  cin >> n >> m;
  ans = n;
  vector<long long> rel(n + 1);
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    if (x < y) {
      if (!rel[x]) ans -= 1;
      rel[x] += 1;
    } else if (x > y) {
      if (!rel[y]) ans -= 1;
      rel[y] += 1;
    }
  }
  cin >> q;
  vector<long long> v(n + 1);
  v = rel;
  while (q--) {
    cin >> o;
    if (o == 3) {
      cout << ans << endl;
      v = rel;
    } else if (o == 2) {
      cin >> x >> y;
      if (x < y) {
        v[x] -= 1;
        if (!v[x]) ans += 1;
      } else {
        v[y] -= 1;
        if (!v[y]) ans += 1;
      }
    } else {
      cin >> x >> y;
      if (x < y) {
        if (!v[x]) ans -= 1;
        v[x] += 1;
      } else if (x > y) {
        if (!v[y]) ans -= 1;
        v[y] += 1;
      }
    }
  }
  return 0;
}
