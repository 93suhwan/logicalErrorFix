#include <bits/stdc++.h>
using namespace std;
const int CL = 3;
const int INF = 1e9 + 7;
vector<pair<int, int> > V[CL];
bool mc1(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
bool mc2(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void rev() {
  for (int i = 0; i < CL; ++i) {
    int sz = V[i].size();
    for (int j = 0; j < sz; ++j) swap(V[i][j].first, V[i][j].second);
  }
}
void revcord() {
  for (int i = 0; i < CL; ++i) {
    int sz = V[i].size();
    for (int j = 0; j < sz; ++j) V[i][j].first = -V[i][j].first;
  }
}
bool checkrow(vector<int> perm, int need) {
  int rx = -INF;
  bool flag = false;
  for (int col : perm) {
    ++rx;
    sort(V[col].begin(), V[col].end(), mc1);
    int cnt = 0;
    for (auto [x, y] : V[col]) {
      if (x >= rx) ++cnt;
      rx = max(x, rx);
      if (cnt == need) break;
    }
    if (cnt != 0) {
      flag = true;
      break;
    }
  }
  if (!flag) return true;
  return false;
}
bool check1(vector<int> perm, int need) {
  bool ans = false;
  for (int u = 0; u < 2; ++u) {
    ans = max(ans, checkrow(perm, need));
    rev();
  }
  return ans;
}
bool mc(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool checkT(vector<int> perm, int need) {
  int rx = -INF;
  sort(V[perm[0]].begin(), V[perm[0]].end());
  int cnt = 0;
  for (auto [x, y] : V[perm[0]]) {
    rx = max(rx, x);
    ++cnt;
    if (cnt == need) break;
  }
  if (cnt != need) return false;
  ++rx;
  sort(V[perm[1]].begin(), V[perm[1]].end(), mc);
  int ry = -INF;
  for (int j = 1; j < CL; ++j) {
    int col = perm[j];
    ++ry;
    int cnt = 0;
    for (auto [x, y] : V[col]) {
      if (x < rx || y < ry) continue;
      ry = max(ry, y);
      ++cnt;
      if (cnt == need) break;
    }
    if (cnt != need) return false;
  }
  return true;
}
bool check2(vector<int> perm, int need) {
  bool ans = false;
  for (int u = 0; u < 2; ++u) {
    for (int u1 = 0; u1 < 2; ++u1) {
      ans = max(ans, checkT(perm, need));
      revcord();
    }
    rev();
  }
  return ans;
}
bool F(int need) {
  vector<int> perm(CL);
  for (int i = 0; i < CL; ++i) perm[i] = i;
  do {
    if (check1(perm, need)) return true;
    if (check2(perm, need)) return true;
  } while (next_permutation(perm.begin(), perm.end()));
  return false;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    c--;
    V[c].push_back({x, y});
  }
  sort(V[0].begin(), V[0].end(), mc1);
  int l = 0, r = n / 3;
  while (l != r) {
    int mid = (l + r + 1) >> 1;
    if (F(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l * 3 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
