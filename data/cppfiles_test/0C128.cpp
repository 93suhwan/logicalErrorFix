#include <bits/stdc++.h>
using namespace std;
int m;
bool comp(pair<string, int> &x, pair<string, int> &y) {
  string sx = x.first, sy = y.first;
  int i = 0;
  while (i < m) {
    if (sx[i] == sy[i])
      i++;
    else
      return i % 2 ? sx[i] > sy[i] : sx[i] < sy[i];
  }
  return true;
}
void solve() {
  int n;
  cin >> n >> m;
  vector<pair<string, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end(), comp);
  for (auto &e : v) cout << e.second << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
