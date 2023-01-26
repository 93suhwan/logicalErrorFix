#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
char str[N];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, res = 0;
    char t;
    cin >> n >> t;
    cin >> str + 1;
    for (long long i = 1; i <= n; i++) res += str[i] != t;
    if (!res)
      cout << 0 << endl;
    else if (str[n] != t) {
      if (res == 1)
        cout << 1 << endl << n - 1 << endl;
      else {
        if (res == n)
          cout << 2 << endl << n - 1 << " " << n << endl;
        else {
          long long k = 1;
          for (long long i = n - 1; i; i--)
            if (str[i] == t) {
              k = i;
              break;
            }
          if (n % k != 0)
            cout << 1 << endl << k << endl;
          else
            cout << 2 << endl << n - 1 << " " << n << endl;
        }
      }
    } else
      cout << 1 << endl << n << endl;
  }
  return 0;
}
