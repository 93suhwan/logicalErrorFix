#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    int skill, neat;
    scanf("%d%d", &skill, &neat);
    points[i] = {skill, neat};
  }
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    if (points[i].first >= d) {
      if (points[i].first >= points[i].second) {
        s.insert({points[i].first, points[i].first});
      } else {
        s.insert({points[i].second, points[i].first});
      }
    }
  }
  if (s.empty()) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 1;
  auto rit = s.begin();
  int r1 = (*rit).first;
  for (auto it = s.begin(); it != s.end(); it++) {
    int L = it->second;
    int R = it->first;
    if (L >= r1) {
      ans++;
      r1 = R;
    }
  }
  printf("%d", ans);
  return 0;
}
