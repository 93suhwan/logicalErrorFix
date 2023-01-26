#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int N = 1e6 + 100;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& x : v) cin >> x;
  vector<vector<int>> track;
  for (int i = 0; i < n; ++i) {
    int ind = max_element(v.begin(), v.end()) - v.begin();
    if (ind != n - i - 1) {
      track.push_back({ind + 1, n - i, 1});
    }
    v.erase(v.begin() + ind);
  }
  cout << track.size() << '\n';
  for (auto x : track) {
    cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
