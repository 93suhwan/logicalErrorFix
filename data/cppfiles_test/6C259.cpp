#include <bits/stdc++.h>
using namespace std;
vector<long long> v(200005);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, x, y, res, q, o;
  cin >> n >> m;
  res = n;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    if (x < y) {
      if (!v[x]) res -= 1;
      v[x] += 1;
    } else if (x > y) {
      if (!v[y]) res -= 1;
      v[y] += 1;
    }
  }
  cin >> q;
  while (q--) {
    cin >> o;
    if (o == 3)
      cout << res << endl;
    else {
      cin >> x >> y;
      if (o == 2) {
        if (x < y) {
          v[x] -= 1;
          if (!v[x]) res += 1;
        } else if (x > y) {
          v[y] -= 1;
          if (!v[y]) res += 1;
        }
      } else {
        if (x < y) {
          if (!v[x]) res -= 1;
          v[x] += 1;
        } else if (x > y) {
          if (!v[y]) res -= 1;
          v[y] += 1;
        }
      }
    }
  }
  return 0;
}
