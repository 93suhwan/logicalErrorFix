#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b, c, d, f, gg = 0, i, j, m, n, t, mod = 1e9 + 7, x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    f = 0;
    vector<long long> v;
    for (i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    f = INT_MAX;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        d = 0;
        for (int k = 0; k < n; k++) {
          a = v[k];
          b = INT_MAX;
          for (int ii = 0; ii <= i; ii++) {
            for (int jj = 0; jj <= j; jj++) {
              long long aa = a - ii - jj * 2;
              if (aa < 0 || aa % 3)
                ;
              else {
                b = min(b, aa / 3);
              }
            }
          }
          d = max(d, b);
        }
        f = min(f, d + i + j);
      }
    }
    cout << f << '\n';
  }
  return 0;
}
