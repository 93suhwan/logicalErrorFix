#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, k = 0, pos, l, c, ans = 0, i, j;
    cin >> n >> m;
    long long int a[n * m], b[n * m];
    vector<pair<long long int, long long int>> v;
    for (i = 0; i < n * m; i++) {
      cin >> a[i];
      v.push_back({a[i], i});
    }
    unordered_map<long long int, pair<bool, long long int>> vis;
    sort(v.begin(), v.end());
    for (auto x : v) {
      b[x.second] = k++;
    }
    for (i = 0; i < n * m; i++) {
      pos = b[i];
      l = pos / m;
      c = 0;
      for (j = pos - 1; j >= l * m; j--) {
        if (vis[j].second != a[i] && vis[j].first == true) {
          c++;
        }
      }
      vis[pos] = {true, a[i]};
      ans += c;
    }
    cout << ans << "\n";
  }
}
