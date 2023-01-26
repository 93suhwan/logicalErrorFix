#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int c[N][4], n;
void init() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= min(i, 3); j++) {
      if (!j)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}
int main() {
  double p;
  cin >> n >> p;
  init();
  for (int i = 0; i <= n - 1; i++)
    if (1.0 * (c[i][3] + c[i][2] * c[n - i][1] + i * c[n - i][2] * 0.5) /
            c[n][3] >=
        p) {
      cout << i;
      break;
    }
  return 0;
}
