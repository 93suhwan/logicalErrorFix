#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long n = a + b;
  if (a == b) {
    cout << 2 << endl;
    cout << 0 << " " << n << endl;
  } else if (n & 1) {
    if (b > a) swap(a, b);
    if (a == 0 || b == 0) {
      cout << 2 << endl;
      cout << n / 2 << " " << (n / 2 + 1) << endl;
    } else {
      long long max = n / 2 + 1 + b;
      long long min = abs(n / 2 + 1 - a);
      cout << max - min + 1 << endl;
      for (long long i = min; i <= max; i++) cout << i << " ";
      cout << endl;
    }
  } else {
    if (b > a) swap(a, b);
    if (a == 0 || b == 0) {
      cout << 1 << endl;
      cout << n / 2 << endl;
    } else {
      long long max = n / 2 + b;
      long long min = abs(a - n / 2);
      vector<long long> ans;
      for (long long i = min; i <= max; i += 2) ans.push_back(i);
      cout << ans.size() << endl;
      {
        for (auto it : ans) cout << it << " ";
        cout << endl;
      }
      cout << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
