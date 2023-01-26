#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int> > > a, suf, pre;
bool side[500500];
void solve() {
  cin >> n >> m;
  a.resize(m, vector<pair<int, int> >(n));
  pre.resize(m, vector<pair<int, int> >(n)),
      suf.resize(m, vector<pair<int, int> >(n));
  for (int i = (0); i <= (n - 1); i++)
    for (int j = (0); j <= (m - 1); j++)
      cin >> a[j][i].first, a[j][i].second = i;
  for (int j = (m - 1); j >= (0); j--) {
    sort(a[j].begin(), a[j].end());
    for (int i = (0); i <= (n - 1); i++) {
      pair<int, int> &seg = suf[j][a[j][i].second];
      if (j == m - 1)
        seg = {i, i};
      else
        seg = suf[j + 1][a[j][i].second], seg.first = max(seg.first, i),
        seg.second = min(seg.second, i);
    }
  }
  for (int j = (0); j <= (m - 1); j++) {
    for (int i = (0); i <= (n - 1); i++) {
      pair<int, int> &seg = pre[j][a[j][i].second];
      if (j == 0)
        seg = {i, i};
      else
        seg = pre[j - 1][a[j][i].second], seg.first = max(seg.first, i),
        seg.second = min(seg.second, i);
    }
  }
  for (int j = (0); j <= (m - 2); j++) {
    bool flag = true;
    int l = 0, r = n - 1;
    for (int i = (0); i <= (n - 1); i++) {
      if (pre[j][i].first < suf[j + 1][i].second) {
        side[i] = 1, l = max(l, pre[j][i].first),
        r = min(r, suf[j + 1][i].second);
      } else if (pre[j][i].second > suf[j + 1][i].first) {
        side[i] = 0, l = max(l, suf[j + 1][i].first),
        r = min(r, pre[j][i].second);
      } else {
        flag = false;
        break;
      }
    }
    if (!flag || r < l) continue;
    cout << "YES\n";
    for (int i = (0); i <= (n - 1); i++) cout << (side[i] ? 'B' : 'R');
    cout << " " << j + 1 << endl;
    return;
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    a.clear(), pre.clear(), suf.clear();
    solve();
  }
  return 0;
}
