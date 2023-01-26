#include <bits/stdc++.h>
using namespace std;
int n, d, s, a;
vector<pair<int, int> > v[2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> s >> a;
    if (s < d) {
      continue;
    }
    if (s >= a) {
      v[0].push_back({s, a});
    } else {
      v[1].push_back({a, s});
    }
  }
  sort((v[0]).begin(), (v[0]).end());
  sort((v[1]).begin(), (v[1]).end());
  int j = 0;
  int ans = (int)v[0].size();
  for (int i = 0; i < (int)v[1].size(); i++) {
    while (j < (int)v[0].size() && v[0][j].first < v[1][i].first) {
      d = max(d, v[0][j++].second);
    }
    if (d <= v[1][i].second) {
      d = max(d, v[1][i].first);
      ans++;
    }
  }
  cout << ans;
}
