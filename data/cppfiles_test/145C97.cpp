#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
const int INF = 1e9 + 2137;
int n, k, par[MAXN], rep[MAXN];
map<pair<int, int>, bool> vis;
struct Mine {
  int x, y, time, i;
};
bool srtx(Mine a, Mine b) { return a.x < b.x; }
bool srty(Mine a, Mine b) { return a.y < b.y; }
int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}
void merge(int x, int y) {
  int px = find(x), py = find(y);
  par[px] = py;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    Mine a[n];
    for (int i = 0; i < n; ++i) {
      int x, y, time;
      cin >> x >> y >> time;
      par[i] = i;
      rep[i] = INF;
      a[i] = Mine{x, y, time, i};
    }
    map<int, vector<Mine>> ver, hor;
    for (int i = 0; i < n; ++i) {
      ver[a[i].y].push_back(a[i]);
      hor[a[i].x].push_back(a[i]);
    }
    for (auto u : ver) {
      sort(u.second.begin(), u.second.end(), srtx);
      int l = 0, r = 0, sz = u.second.size();
      for (l = 0; l < sz; ++l) {
        r = max(l + 1, r);
        while (r < sz) {
          if (u.second[l].x + k >= u.second[r].x) {
            merge(u.second[r].i, u.second[l].i);
          } else
            break;
          ++r;
        }
      }
    }
    for (auto u : hor) {
      sort(u.second.begin(), u.second.end(), srty);
      int l = 0, r = 0, sz = u.second.size();
      for (l = 0; l < sz; ++l) {
        r = max(l + 1, r);
        while (r < sz) {
          if (u.second[l].y + k >= u.second[r].y) {
            merge(u.second[r].i, u.second[l].i);
          } else
            break;
          ++r;
        }
      }
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      rep[find(a[i].i)] = min(rep[find(a[i].i)], a[i].time);
    }
    for (int i = 0; i < n; ++i)
      if (find(a[i].i) == a[i].i) v.push_back(rep[a[i].i]);
    int l = 0, r = n - 1, ans = n - 1;
    while (l <= r) {
      int m = (l + r) / 2, c = 0;
      for (auto u : v) {
        if (u > m) ++c;
      }
      if (c <= m + 1) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << ans << endl;
  }
}
