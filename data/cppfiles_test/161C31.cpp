#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return ((a.second - a.first) < (b.second - b.first));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> r(n);
    for (auto &x : r) cin >> x.first >> x.second;
    sort(r.begin(), r.end(), cmp);
    vector<int> a(n + 1), ans(n);
    for (int i = 0; i < n; i++) {
      for (int j = r[i].first; j <= r[i].second; j++) {
        if (a[j] != 1) {
          ans[i] = j;
          a[j] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++)
      cout << r[i].first << " " << r[i].second << " " << ans[i] << "\n";
    cout << "\n";
  }
  return 0;
}
