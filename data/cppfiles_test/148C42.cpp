#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, INF = 0x3f3f3f3f;
void solve() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  int maxn = 0;
  int minn = INF;
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    maxn = max(maxn, x);
    minn = min(minn, x);
  }
  ans = max(ans, (long long)(maxn - minn) * m);
  cin >> q;
  maxn = 0, minn = INF;
  while (q--) {
    int x;
    cin >> x;
    maxn = max(maxn, x);
    minn = min(minn, x);
  }
  ans = max(ans, (long long)(maxn - minn) * m);
  cin >> q;
  maxn = 0, minn = INF;
  while (q--) {
    int x;
    cin >> x;
    maxn = max(maxn, x);
    minn = min(minn, x);
  }
  ans = max(ans, (long long)(maxn - minn) * n);
  cin >> q;
  maxn = 0, minn = INF;
  while (q--) {
    int x;
    cin >> x;
    maxn = max(maxn, x);
    minn = min(minn, x);
  }
  ans = max(ans, (long long)(maxn - minn) * n);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
