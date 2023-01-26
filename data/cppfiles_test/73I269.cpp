#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j, flg = 0, cnt = 0;
    cin >> n;
    long long int ar[n + 1];
    for (i = 1; i <= n; i++) cin >> ar[i];
    while (1) {
      int p = 0, idx = 1;
      for (i = 1; i < n; i++) {
        if (ar[i] > ar[i + 1]) {
          idx = i;
          break;
        }
      }
      if (idx % 2 == 1) {
        for (i = 1; i <= (n - 2); i += 2) {
          if (ar[i] > ar[i + 1]) swap(ar[i], ar[i + 1]);
        }
      } else {
        for (i = 2; i <= (n - 1); i += 2) {
          if (ar[i] > ar[i + 1]) swap(ar[i], ar[i + 1]);
        }
      }
      for (i = 1; i <= n; i++) {
        if (i != ar[i]) p = 1;
      }
      if (p)
        cnt++;
      else
        break;
    }
    if (cnt == 0)
      cout << cnt << endl;
    else
      cout << cnt + 1 << endl;
  }
  return 0;
}
