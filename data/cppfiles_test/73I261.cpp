#include <bits/stdc++.h>
using namespace std;
long long t, n, a[1009];
string s;
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long cnt = 1, ant = 0, c = 0;
    while (cnt) {
      cnt = 0;
      for (long long i = c % 2; i < n - 2 + c % 2; i += 2)
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          cnt++;
        }
      if (cnt) ant++;
      c++;
    }
    cout << ant << endl;
  }
  return 0;
}
