#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[15] = {0};
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int N = 1;
    for (int i = 1; i <= n; i++) {
      N *= 3;
    }
    N--;
    for (int i = 1; i <= N; i++) {
      int k = i;
      int sum = 0;
      for (int j = 1; j <= 10; j++) {
        int sign = k % 3;
        if (sign == 2) {
          sign = -1;
        }
        sum += sign * a[j];
        k /= 3;
      }
      if (sum == 0) {
        cout << "YES\n";
        goto m1;
      }
    }
    cout << "NO\n";
  m1:;
  }
}
