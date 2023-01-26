#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int k = 0; k < n; ++k) {
    int m;
    cin >> m;
    int a = 1, b = 1, i = 1, j = 1;
    while (1) {
      j = b;
      i = 1;
      if (a + b - 1 >= m) {
        cout << i + m - a - 1 << " " << j << '\n';
        break;
      }
      i += b - 1;
      if (b == 1)
        a += b - 1;
      else
        a += b;
      if (a + b - 1 >= m) {
        cout << i << " " << j - m + a << '\n';
        break;
      }
      j -= b - 1;
      a += b - 1;
      b += 1;
    }
  }
  return 0;
}
