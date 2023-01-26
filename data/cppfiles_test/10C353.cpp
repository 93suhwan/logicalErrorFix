#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 5;
map<int, vector<int>> ind;
int ans[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    memset(ans, 0, n * sizeof(ans[0]));
    ind.clear();
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (ind[x].size() < k) {
        ind[x].push_back(i);
      }
    }
    int m = 0;
    for (auto i : ind) m += i.second.size();
    m -= m % k;
    int cnt = 0;
    for (auto e : ind)
      for (auto i : e.second) {
        ans[i] = ++cnt;
        cnt %= k;
        if (--m == 0) goto _output;
      }
  _output:
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
