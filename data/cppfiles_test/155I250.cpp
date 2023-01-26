#include <bits/stdc++.h>
using namespace std;
long long const N = 1e6 + 5;
long long a[N];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    string s;
    cin >> s;
    for (long long i = 0; i < n - 1; i++) {
      if (s[i] == '0') {
        if (s[i + 1] == '0')
          continue;
        else {
          if (a[i + 1] > a[i])
            continue;
          else
            swap(a[i], a[i + 1]);
        }
      } else {
        if (s[i + 1] == '1')
          continue;
        else {
          if (a[i] > a[i + 1])
            continue;
          else
            swap(a[i], a[i + 1]);
        }
      }
    }
    for (long long i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
  }
}
