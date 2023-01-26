#include <bits/stdc++.h>
using namespace std;
void solve() {
  map<long long, long long> m;
  long long n, x;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  stack<long long> zyada;
  long long sum = 0, it = 0;
  bool temp = false, yu = false;
  for (long long i = 0; i <= n; i++) {
    if (m[i] != 0) {
      cout << sum + m[i] << " ";
      for (long long u = 2; u <= m[i]; u++) zyada.push(i);
    } else {
      if (!temp) {
        cout << 0 << " ";
      }
      if (temp) cout << sum << " ";
      if (zyada.empty()) {
        it = i;
        break;
      }
      sum += (i - zyada.top());
      zyada.pop();
      temp = true;
    }
  }
  for (long long i = it + 1; i <= n; i++) cout << -1 << " ";
  cout << endl;
}
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
