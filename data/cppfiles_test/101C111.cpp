#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long INF = 1e18;
const int mod = 998244353;
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return add(x, y == 0 ? 0 : mod - y); }
inline int mul(int x, int y) { return (int)((long long)x * y % mod); }
bool cx[1000010], cy[1000010];
vector<int> vx[1000010], vy[1000010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int tci = 0; tci < tc; tci++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> xv(n), yv(m);
    vector<pair<int, int> > pv(k);
    for (int& t : xv) cin >> t, cx[t] = 1;
    for (int& t : yv) cin >> t, cy[t] = 1;
    vector<int> x2v = xv, y2v = yv;
    for (pair<int, int>& t : pv) {
      cin >> t.first >> t.second;
      if (!cx[t.first]) vx[t.first].emplace_back(t.second);
      if (!cy[t.second]) vy[t.second].emplace_back(t.first);
      x2v.emplace_back(t.first), y2v.emplace_back(t.second);
    }
    sort((x2v).begin(), (x2v).end());
    x2v.erase(unique((x2v).begin(), (x2v).end()), x2v.end());
    sort((y2v).begin(), (y2v).end());
    y2v.erase(unique((y2v).begin(), (y2v).end()), y2v.end());
    long long ans = 0;
    vector<int> swp;
    for (int& t : x2v) {
      if (cx[t]) {
        sort((swp).begin(), (swp).end());
        int nn = swp.size();
        ans += (long long)nn * nn;
        for (int i = 0; i < nn;) {
          int j = i + 1;
          while (j < nn && swp[j] == swp[i]) j++;
          int mm = j - i;
          ans -= (long long)mm * mm;
          i = j;
        }
        swp.clear();
      }
      for (int& t : vx[t]) swp.emplace_back(t);
    }
    for (int& t : y2v) {
      if (cy[t]) {
        sort((swp).begin(), (swp).end());
        int nn = swp.size();
        ans += (long long)nn * nn;
        for (int i = 0; i < nn;) {
          int j = i + 1;
          while (j < nn && swp[j] == swp[i]) j++;
          int mm = j - i;
          ans -= (long long)mm * mm;
          i = j;
        }
        swp.clear();
      }
      for (int& t : vy[t]) swp.emplace_back(t);
    }
    for (int& t : x2v) cx[t] = 0, vx[t].clear();
    for (int& t : y2v) cy[t] = 0, vy[t].clear();
    ans /= 2;
    cout << ans << '\n';
  }
  return 0;
}
