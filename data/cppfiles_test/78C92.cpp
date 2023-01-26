#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const int N = 2e5 + 100, K = 31, INF = 2e18, MOD = 1e9 + 7;
int t, n, a[N], cnt[K];
void solve() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    fill(cnt, cnt + K, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < K; j++) {
        if ((a[i] >> j) & 1) {
          cnt[j]++;
        }
      }
    }
    map<int, int> ma;
    int e = 0;
    for (int i = 0; i < K; i++) {
      if (cnt[i] > 0) e++;
      for (int j = 1; j <= cnt[i]; j++) {
        if (cnt[i] % j == 0) {
          ma[j]++;
        }
      }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (ma[i] == e) {
        ans.push_back(i);
      }
    }
    for (int x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
