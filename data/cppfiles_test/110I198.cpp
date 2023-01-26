#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<pair<int, int>>> p;
vector<int> ord = {0, 1, 2};
bool solveLine(int k) {
  int lst = -2e9;
  for (int i : ord) {
    sort((p[i]).begin(), (p[i]).end());
    bool found = false;
    for (int j = 0; j < p[i].size(); j++) {
      if (p[i][j].first >= lst) {
        if (j + k - 1 >= p[i].size()) return false;
        lst = p[i][j + k - 1].first;
        found = true;
        break;
      }
    }
    if (!found) return false;
  }
  return true;
}
bool solveGroup(int k) {
  sort((p[ord[0]]).begin(), (p[ord[0]]).end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  int to = p[ord[0]][k - 1].second;
  vector<int> a, b;
  for (int i = 0; i < p[1].size(); i++) {
    if (p[ord[1]][i].second > to) a.push_back(p[ord[1]][i].first);
    if (p[ord[2]][i].second > to) b.push_back(p[ord[2]][i].first);
  }
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  int lst = -2e9;
  bool found = false;
  for (int j = 0; j < a.size(); j++) {
    if (a[j] >= lst) {
      if (j + k - 1 >= a.size()) return false;
      lst = a[j + k - 1];
      found = true;
      break;
    }
  }
  if (!found) return false;
  for (int j = 0; j < b.size(); j++) {
    if (b[j] >= lst) {
      if (j + k - 1 >= b.size()) return false;
      lst = b[j + k - 1];
      return true;
    }
  }
  return false;
}
bool can(int k) {
  sort((ord).begin(), (ord).end());
  do {
    for (int t = 0; t < 2; t++) {
      for (int x = 0; x < 3; x++)
        for (int y = 0; y < p[x].size(); y++)
          swap(p[x][y].first, p[x][y].second);
      for (int i = 0; i < 2; i++) {
        for (int x = 0; x < 3; x++)
          for (int y = 0; y < p[x].size(); y++) p[x][y].first *= -1;
        for (int j = 0; j < 2; j++) {
          for (int x = 0; x < 3; x++)
            for (int y = 0; y < p[x].size(); y++) p[x][y].second *= -1;
          bool res = solveLine(k) | solveGroup(k);
          if (res) return true;
        }
      }
    }
  } while (next_permutation((ord).begin(), (ord).end()));
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  p.resize(3);
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    c--;
    p[c].push_back({x, y});
  }
  int lo = 1, hi = n / 3, ans = 1;
  while (lo <= hi) {
    int md = (lo + hi) / 2;
    if (can(md)) {
      lo = md + 1;
      ans = md;
    } else
      hi = md - 1;
  }
  cout << ans * 3 << '\n';
}
