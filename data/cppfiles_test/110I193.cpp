#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 3;
vector<pair<int, int> > px[3];
vector<pair<int, int> > py[3];
int ctx(int c, int x) {
  return lower_bound(px[c].begin(), px[c].end(), pair<int, int>{x, INF}) -
         px[c].begin();
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int h = n / 3;
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    px[c - 1].push_back({x, y});
    py[c - 1].push_back({y, x});
  }
  int fans = 0;
  for (int di = 0; di < 4; di++) {
    for (int c = 0; c < 3; c++) {
      sort(px[c].begin(), px[c].end());
      sort(py[c].begin(), py[c].end());
    }
    int st = 1, en = h;
    while (st < en) {
      int mi = (st + en + 1) / 2;
      int p[3] = {0, 1, 2};
      bool yes = 0;
      do {
        bool legit = 1;
        int cx = -INF - 1;
        for (int i = 0; i < 3; i++) {
          int curpos = ctx(p[i], cx);
          if (curpos + mi > h) {
            legit = 0;
            break;
          }
          cx = px[p[i]][curpos + mi - 1].first;
        }
        if (legit) {
          yes = 1;
          break;
        }
      } while (next_permutation(p, p + 3));
      if (yes) {
        st = mi;
        continue;
      }
      do {
        bool legit = 1;
        int cx = px[p[0]][mi - 1].first;
        int ny = 0, cy1 = INF, cy2 = -INF;
        for (int j = 0; j < h; j++) {
          pair<int, int> pt = py[p[1]][j];
          if (pt.second <= cx) continue;
          ny++;
          if (ny >= mi) {
            cy1 = pt.first;
            break;
          }
        }
        ny = 0;
        for (int j = h - 1; j >= 0; j--) {
          pair<int, int> pt = py[p[2]][j];
          if (pt.second <= cx) continue;
          ny++;
          if (ny >= mi) {
            cy2 = pt.first;
            break;
          }
        }
        legit = cy1 < cy2;
        if (legit) {
          yes = 1;
          break;
        }
      } while (next_permutation(p, p + 3));
      if (yes) {
        st = mi;
      } else {
        en = mi - 1;
      }
    }
    fans = max(fans, st);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < h; j++) {
        pair<int, int> &pt = px[i][j];
        pt = {-pt.second, pt.first};
      }
    }
  }
  cout << fans * 3;
}
