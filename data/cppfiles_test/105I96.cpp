#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long a[n], b[n], ans[n], m[n];
    set<long long> s;
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> m[i];
      s.insert(a[i] + b[i] - m[i]);
      ans[i] = min(b[i], m[i]);
    }
    cout << (long long)s.size() << "\n";
    for (int i = 0; i < n; i++) {
      cout << m[i] - ans[i] << " " << ans[i] << "\n";
    }
  }
  return 0;
}
