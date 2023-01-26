#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e+16;
const int SMALL_INF = 1998244353;
const int NSIZE = 2 * 1e+5 + 1000;
const int _NSIZE = 1000;
const long long MOD = 998244353;
const long double EPS = 1e-12;
const int MAX = 1e+6 + 1000;
const long double PI = atan(1) * 4;
const long long HZ = -692281337;
const long long UNUSED = SMALL_INF;
struct Dish {
  int a, b, m, idx;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Dish> d(n);
    vector<pair<int, int> > seg(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i].a >> d[i].b >> d[i].m;
      int r = d[i].b >= d[i].m ? d[i].a - d[i].b + d[i].m
                               : d[i].a - d[i].m + d[i].b;
      int l = d[i].a >= d[i].m ? d[i].a - d[i].m - d[i].b
                               : d[i].m - d[i].b - d[i].a;
      seg[i] = {l, r};
      d[i].idx = i;
    }
    sort(d.begin(), d.end(),
         [&](Dish p, Dish q) { return p.a + p.b - p.m < q.a + q.b - q.m; });
    int difcnt = 0;
    vector<pair<int, int> > ans(n, {-1, -1});
    for (int i = 0; i < n;) {
      int j = i;
      vector<pair<int, int> > line;
      while (true) {
        line.push_back({seg[d[j].idx].first, -(j + 1)});
        line.push_back({seg[d[j].idx].second, j + 1});
        if (j < n - 1 &&
            d[j].a + d[j].b - d[j].m == d[j + 1].a + d[j + 1].b - d[j + 1].m)
          j++;
        else
          break;
      }
      sort(line.begin(), line.end());
      vector<Dish> h;
      for (auto k : line) {
        int ind = abs(k.second) - 1;
        if (k.second < 0) {
          h.push_back(d[ind]);
        } else if (ans[d[ind].idx] == make_pair(-1, -1)) {
          difcnt++;
          while (!h.empty()) {
            Dish now = h.back();
            h.pop_back();
            ans[now.idx] = now.b >= now.m ? make_pair(0, now.m)
                                          : make_pair(now.m - now.b, now.b);
            ans[now.idx].first += (seg[now.idx].second - k.first) / 2;
            ans[now.idx].second -= (seg[now.idx].second - k.first) / 2;
          }
        }
      }
      i = j + 1;
    }
    cout << difcnt << endl;
    for (auto i : ans) cout << i.first << " " << i.second << endl;
  }
}
