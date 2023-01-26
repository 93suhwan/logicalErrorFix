#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i].first == v[i].second) {
      cout << v[i].first << " " << v[i].second << " " << v[i].first << endl;
      continue;
    }
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (v[j].first == v[i].first && v[j].second <= v[i].second) {
        cout << v[i].first << " " << v[i].second << " " << v[j].second + 1
             << endl;
        break;
      }
      if (v[j].first >= v[i].first && v[j].second == v[i].second) {
        cout << v[i].first << " " << v[i].second << " " << v[j].first - 1
             << endl;
        break;
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
