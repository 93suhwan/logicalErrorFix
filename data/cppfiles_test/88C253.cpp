#include <bits/stdc++.h>
using namespace std;
long long a[100010];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0)
      cout << "YES" << endl;
    else {
      long long flag = 0;
      for (long long i = 1; i < n; i++) {
        if (a[i] >= a[i + 1]) {
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
