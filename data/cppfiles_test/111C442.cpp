#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int n, i, j;
    int sum0 = 0, sum1 = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
      int a[105] = {0};
      for (j = i + 1; j <= 2 * i; j++) {
        a[j] = 1;
      }
      for (j = 2 * i + 2; j <= 2 * n; j += 2) {
        a[j] = 1;
      }
      for (j = 1; j <= 2 * n; j++) {
        if (a[j])
          cout << ")";
        else
          cout << "(";
      }
      cout << endl;
    }
  }
  return 0;
}
