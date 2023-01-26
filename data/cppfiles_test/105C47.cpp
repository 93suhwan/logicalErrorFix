#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m;
long long a[N], b[N], w[N];
long long ans[N];
void solve() {
  map<long long, vector<int> > id;
  cin >> n;
  for (int i = 1; i <= n; i++) ans[i] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> w[i];
    id[a[i] + b[i] - w[i]].push_back(i);
  }
  long long tot = 0;
  for (auto x : id) {
    vector<int> p = x.second;
    sort(p.begin(), p.end(), [&](int x, int y) {
      return (a[x] - max(0ll, w[x] - b[x])) < (a[y] - max(0ll, w[y] - b[y]));
    });
    long long M = -1e9;
    for (auto i : p) {
      if (a[i] - M > w[i]) {
        tot++;
        ans[i] = max(0ll, w[i] - b[i]);
        M = a[i] - ans[i];
      } else
        ans[i] = a[i] - M;
    }
  }
  cout << tot << '\n';
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ' << w[i] - ans[i] << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
