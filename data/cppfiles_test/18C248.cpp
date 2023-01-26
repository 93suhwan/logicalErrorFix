#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> all(k);
  vector<bool> used(2 * n);
  for (int i = 0; i < k; i++) {
    cin >> all[i].first >> all[i].second;
    all[i].first--;
    all[i].second--;
    used[all[i].first] = 1;
    used[all[i].second] = 1;
  }
  vector<int> ost;
  for (int i = 0; i < 2 * n; i++) {
    if (used[i]) continue;
    ost.push_back(i);
  }
  int h = ost.size() / 2;
  for (int i = 0; i * 2 < ost.size(); i++) {
    all.push_back({ost[i], ost[i + h]});
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int y = 0; y < n; y++) {
      if (i == y) continue;
      int l1 = all[i].first;
      int r1 = all[i].second;
      if (l1 > r1) swap(l1, r1);
      int j = 0;
      if (all[y].first > l1 && all[y].first < r1) j++;
      if (all[y].second > l1 && all[y].second < r1) j++;
      if (j == 1) sum++;
    }
  }
  cout << sum / 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t) {
    t--;
    solve();
  }
}
