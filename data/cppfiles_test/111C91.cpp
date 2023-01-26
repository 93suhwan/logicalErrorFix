#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n;
int a[N];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int k = 0; k < n; k++) {
      for (int i = 1; i <= n - 1; i++) {
        cout << '(';
      }
      int j;
      for (j = 1; j <= k; j++) {
        cout << ')';
      }
      cout << '(';
      for (int q = 1; q <= n - j + 1; q++) {
        cout << ')';
      }
      puts("");
    }
  }
  return 0;
}
