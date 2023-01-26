#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  int ttx;
  cin >> ttx;
  while (ttx--) {
    cin >> n >> m >> k;
    int c = n % m, pre = 0;
    for (int i = 1; i <= k; i++) {
      int x;
      int t = 0, sum = 0;
      for (int j = 0; j <= n - 1; j++) {
        x = (pre + j) % n + 1;
        if (sum == 0) {
          if (j) cout << endl;
          sum = n / m;
          if (t < c) {
            t++;
            sum++;
          }
          cout << sum;
        }
        cout << ' ' << x;
        sum--;
      }
      cout << endl;
      pre = pre + c * (n / m + 1);
      pre %= n;
    }
    if (ttx) cout << endl;
  }
  return 0;
}
