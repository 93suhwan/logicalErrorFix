#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long t;
set<long long> s;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc;
  cin >> tc;
  while (tc--) {
    cin >> a >> b;
    s.clear();
    if (a < b) swap(a, b);
    t = (a + b) / 2;
    for (long long i = 0; i <= b; i++) {
      s.insert(a - t + 2 * i);
    }
    if ((a + b) % 2 == 1) {
      t++;
      for (long long i = 0; i <= b; i++) {
        s.insert(a - t + 2 * i);
      }
    }
    cout << s.size() << '\n';
    for (auto x : s) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}
