#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    unordered_map<long long, long long> a;
    long long tt;
    for (long long i = 0; i < n; i++) {
      cin >> tt;
      a[tt]++;
    }
    cout << a[0] << ' ';
    map<long long, long long> don;
    long long ans = 0;
    if (a[0] == 0) {
      ans = -1;
    } else {
      if (a[0] > 1) don[0] = (a[0] - 1);
    }
    long long fil = 0;
    for (long long i = 1; i <= n; i++) {
      long long a2 = 0;
      if (ans == -1) {
        cout << -1 << ' ';
        continue;
      }
      a2 += a[i];
      a2 += fil;
      cout << a2 << ' ';
      if (a[i] > 1) {
        don[i] = (a[i] - 1);
      } else if (a[i] == 0) {
        if (don.size() > 0) {
          auto it = don.end();
          it--;
          fil += (i - it->first);
          it->second--;
          if (it->second == 0) {
            don.erase(it->first);
          }
        } else {
          ans = -1;
        }
      }
    }
    cout << endl;
  }
}
