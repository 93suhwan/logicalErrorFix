#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
vector<pair<int, int> > byx[4][3], byy[4][3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  vector<vector<pair<int, int> > > a(3);
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    pair<int, int> p;
    int c;
    cin >> p.first >> p.second >> c;
    --c;
    a[c].push_back(p);
  }
  for (int z = 0; z < (int)(4); ++z) {
    for (int c = 0; c < (int)(3); ++c) {
      byx[z][c] = a[c];
      sort((byx[z][c]).begin(), (byx[z][c]).end());
      byy[z][c] = a[c];
      sort((byy[z][c]).begin(), (byy[z][c]).end(),
           [&](pair<int, int> a, pair<int, int> b) {
             return a.second < b.second;
           });
      for (auto &p : a[c]) {
        swap(p.first, p.second);
        p.second = -p.second;
      }
    }
  }
  int L = 0, R = n / 3 + 1;
  while (R - L > 1) {
    int M = (L + R) / 2;
    bool ok = false;
    for (int z = 0; z < (int)(4); ++z)
      for (int c = 0; c < (int)(3); ++c) {
        int lx = byx[z][c][M - 1].first + 1;
        vector<vector<pair<int, int> > > b(2);
        for (int d = 0; d < (int)(2); ++d) {
          int cc = (c + 1 + d) % 3;
          for (auto p : byy[z][cc])
            if (p.first >= lx) b[d].push_back(p);
        }
        if (b[0].size() < M || b[1].size() < M) continue;
        for (int z = 0; z < (int)(2); ++z)
          ok |= b[z][M - 1].second < b[z ^ 1].end()[-M].second;
        for (int d = 0; d < (int)(2); ++d) {
          int lxx = lx;
          bool good = true;
          for (int e = 0; e < (int)(2); ++e) {
            int cc = (c + 1 + (d ^ e)) % 3;
            auto it1 = lower_bound((byx[z][cc]).begin(), (byx[z][cc]).end(),
                                   make_pair(lxx, -1));
            if (byx[z][cc].end() - it1 < M) {
              good = false;
              break;
            }
            lxx = (it1 + M - 1)->first + 1;
          }
          if (good) ok = true;
        }
      }
    (ok ? L : R) = M;
  }
  cout << 3 * L << '\n';
  return 0;
}
