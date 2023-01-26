#include <bits/stdc++.h>
using namespace std;
char ar[300200], br[300200];
int main() {
  ios_base::sync_with_stdio(false);
  long long int t, j;
  cin >> t;
  for (j = 0; j < t; j++) {
    long long int y, f, w = 20020000, i, x = 1, m = 0, a = 0, b = 0, c = 0, d,
                        an, bn;
    long long int ab = 998244353, ba = 0, n, x1, x2, y2, h, k = 0, z = 0,
                  ac = 0, bc = 0, s = 0, dr[100][5];
    cin >> ar;
    n = strlen(ar);
    for (i = 1; i < n; i++) {
      x = (ar[i] - 'a') - (ar[i - 1] - 'a');
      if (x < 0) x = -x;
      a += x;
    }
    cout << a << endl;
  }
}
