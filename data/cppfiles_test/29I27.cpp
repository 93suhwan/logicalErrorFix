#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  long long t, n, m, x, a, b, c, i, j, k, cnt = 0, l, r, mid, mxf, sumf;
  bool ok;
  cin >> t;
  while (t--) {
    cin >> n;
    a = b = 0;
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x == 1)
        a++;
      else if (x == 0)
        b++;
    }
    cout << a + a * (pow(2, b) - 1) << '\n';
  }
}
