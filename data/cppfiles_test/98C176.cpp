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
    long long int ab[30], ba = 0, n, x1, x2, y2, h, k = 0, z = 0, ac = 0,
                          bc = 0, s = 0, dr[100][5];
    cin >> br >> ar;
    for (i = 0; i < 26; i++) {
      x = br[i] - 'a';
      ab[x] = i;
    }
    n = strlen(ar);
    for (i = 1; i < n; i++) {
      x = (ar[i] - 'a');
      y = (ar[i - 1] - 'a');
      x = ab[x] - ab[y];
      if (x < 0) x = -1 * x;
      a += x;
    }
    cout << a << endl;
  }
}
