#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
char str[N];
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, res = 0;
    char t;
    cin >> n >> t >> str + 1;
    for (long long i = 1; i <= n; i++) res += str[i] != t;
    if (!res)
      cout << 0 << endl;
    else if (str[n] != t) {
      if (res == 1)
        cout << 1 << endl << n - 1 << endl;
      else
        cout << 2 << endl << n - 1 << " " << n << endl;
    } else
      cout << 1 << endl << n << endl;
  }
  return 0;
}
