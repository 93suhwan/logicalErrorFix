#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, cnt = 0, j, flg = 0, f;
    cin >> n;
    long long int ar[n + 2];
    vector<long long int> v;
    for (i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    for (i = 1; i <= n; i++) {
      if (ar[i] != i) flg = 1;
    }
    if (flg == 0)
      cout << "0" << endl;
    else {
      while (1) {
        for (i = 1; i < n; i++) {
          if (ar[i] > ar[i + 1]) break;
        }
        if (i & 1 == 1) {
          for (i = 1; i <= (n - 2); i += 2) {
            if (ar[i] > ar[i + 1]) swap(ar[i], ar[i + 1]);
          }
        } else {
          for (i = 2; i <= (n - 1); i += 2) {
            if (ar[i] > ar[i + 1]) swap(ar[i], ar[i + 1]);
          }
        }
        f = 0;
        for (i = 1; i <= n; i++) {
          if (i != ar[i]) f = 1;
        }
        if (f)
          cnt++;
        else
          break;
      }
      cout << cnt + 1 << endl;
    }
  }
  return 0;
}
