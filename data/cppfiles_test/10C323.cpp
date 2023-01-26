#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> as(n);
    vector<int> assigns(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> as[i].first;
      as[i].second = i;
    }
    sort(as.begin(), as.end());
    int cur = -1;
    int curcount = 0;
    int turn = 1;
    set<int> lastset;
    for (auto it : as) {
      if (cur == it.first) {
        curcount++;
      } else {
        curcount = 0;
      }
      cur = it.first;
      if (curcount >= k) {
        continue;
      }
      assigns[it.second] = turn;
      lastset.insert(it.second);
      turn++;
      if (turn > k) {
        turn = 1;
        lastset.clear();
      }
    }
    for (auto i : lastset) {
      assigns[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      cout << assigns[i] << " ";
    }
    cout << "\n";
  }
}
