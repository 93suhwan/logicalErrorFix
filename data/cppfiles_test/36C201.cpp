#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long mid = n >> 1;
    if (mid - 1 >= 1) {
      for (long long i = 1; i <= mid; i++) cout << 'a';
      char c = 'b';
      for (long long i = mid + 1; i <= n - mid + 1; i++) {
        cout << c;
        c++;
      }
      for (long long i = n - mid + 2; i <= n; i++) cout << 'a';
      cout << endl;
    } else {
      char c = 'a';
      for (long long i = 1; i <= n; i++) {
        cout << c;
        c++;
      }
      cout << endl;
    }
  }
}
