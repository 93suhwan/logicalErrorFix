#include <bits/stdc++.h>
using namespace std;
const long long N = 32;
long long timer, cc1, cc;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  boost();
  long long i, t, q, l, r, ans, mid, c = 0, j, z, tc, n, k;
  long long h, m, u, mm, w, x, y, l1, r1, d = 0, mask, v, mx;
  long double f, f1;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a[n];
    mx = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > mx) {
        z = i + 1;
        mx = a[i];
      }
    }
    l = max((long long)0, mx - z);
    cout << l << '\n';
  }
  return 0;
}
