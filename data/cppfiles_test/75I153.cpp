#include <bits/stdc++.h>
using namespace std;
const long long inf = (1ll << 62);
long long t = 1;
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long> > a(n + 1);
  vector<long long> b(n + 1);
  for (long long i = 1; i <= n; i++) {
    long long s;
    cin >> s;
    a[i].resize(s);
    long long mx = 0;
    for (long long j = 0; j < s; j++) {
      cin >> a[i][j];
      mx = max(a[i][j] - j, mx);
    }
    b[i] = mx;
  }
  sort(b.begin() + 1, b.end());
  long long c = b[1] + 1 + (int)a[1].size(), ans = b[1] + 1;
  for (long long i = 2; i <= n; i++) {
    ans += max(0ll, b[i] + 1 - c);
    c += (int)a[i].size();
  }
  cout << ans;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
