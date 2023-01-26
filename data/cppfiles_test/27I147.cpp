#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string a, b;
    long long z = 1;
    cin >> a >> b;
    long long f = 0;
    for (long long i = 0; i < a.size(); i++) {
      if (f < b.size() && i % 2 == z && a[i] == b[f]) {
        z ^= 1;
        f++;
      }
    }
    bool ans = false;
    if (f == b.size()) ans = true;
    z = 0;
    f = 0;
    for (long long i = 0; i < a.size(); i++) {
      if (f < b.size() && i % 2 == z && a[i] == b[f]) {
        z ^= 1;
        f++;
      }
    }
    if (f == b.size()) ans = true;
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
