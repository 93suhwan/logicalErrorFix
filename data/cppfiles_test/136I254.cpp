#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n, 0);
  bool t = true;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < n) t = false;
  }
  if (!t) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (long long i = 0; i < n; i++) cout << 1 << " ";
    cout << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long x = 1; x < t + 1; x++) {
    solve();
  }
  return 0;
}
