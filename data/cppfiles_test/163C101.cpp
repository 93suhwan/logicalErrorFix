#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
long long int power(long long int x, long long int n) {
  if (n == 0) return 1;
  if (x % 1000000007 == 0) return 0;
  long long int pow = 1;
  while (n) {
    if (n & 1) pow = (pow * x) % 1000000007;
    n = n >> 1;
    x = (x * x) % 1000000007;
  }
  return pow;
}
pair<long long int, long long int> composite(
    pair<long long int, long long int> a,
    pair<long long int, long long int> b) {
  pair<long long int, long long int> tmp =
      make_pair((a.first + a.second * b.first) % 1000000007,
                (a.second * b.second) % 1000000007);
  return tmp;
}
void solve(int ttt) {
  int n, m, rb, cb, rd, cd, pp;
  cin >> n >> m >> rb >> cb >> rd >> cd >> pp;
  long long int inv100 = power(100, 1000000007 - 2);
  long long int p = (inv100 * pp) % 1000000007;
  p = (1 - p + 1000000007) % 1000000007;
  int dx = 1, dy = 1;
  int cx = rb;
  int cy = cb;
  vector<pair<long long int, long long int> > st;
  map<pair<pair<int, int>, pair<int, int> >, int> mStI;
  while (1) {
    int hitX, hitY;
    int ndx = dx, ndy = dy;
    int t;
    auto state = make_pair(make_pair(cx, cy), make_pair(dx, dy));
    if (mStI.count(state)) {
      int ind = mStI[state];
      pair<long long int, long long int> cur = make_pair(0ll, 1ll);
      for (int i = ind; i < st.size(); i++) {
        cur = composite(cur, st[i]);
      }
      1;
      long long int denom =
          power((1 - cur.second + 1000000007) % 1000000007, 1000000007 - 2);
      long long int ans = (cur.first * denom) % 1000000007;
      pair<long long int, long long int> cur2 = make_pair(0ll, 1ll);
      for (int i = 0; i < ind; i++) {
        cur2 = composite(cur2, st[i]);
      }
      ans = (cur2.first + cur2.second * ans) % 1000000007;
      if (rb == rd || cb == cd) {
        ans = (ans * p) % 1000000007;
      }
      cout << ans << "\n";
      break;
    }
    mStI[state] = st.size();
    1;
    if (dx == 1) {
      int possX = n;
      int possY = (possX - cx) * dy + cy;
      if (possY >= 1 && possY <= m) {
        t = possX - cx;
        hitX = possX;
        hitY = possY;
        ndx = -1;
      }
    } else {
      int possX = 1;
      int possY = (cx - possX) * dy + cy;
      if (possY >= 1 && possY <= m) {
        t = cx - possX;
        hitX = possX;
        hitY = possY;
        ndx = 1;
      }
    }
    if (dy == 1) {
      int possY = m;
      int possX = (possY - cy) * dx + cx;
      if (possX >= 1 && possX <= n) {
        t = possY - cy;
        hitX = possX;
        hitY = possY;
        ndy = -1;
      }
    } else {
      int possY = 1;
      int possX = (cy - possY) * dx + cx;
      if (possX >= 1 && possX <= n) {
        t = cy - possY;
        hitX = possX;
        hitY = possY;
        ndy = 1;
      }
    }
    vector<pair<int, int> > times;
    times.push_back(make_pair(0, 0));
    times.push_back(make_pair(t, 0));
    if (abs(hitX - cx) == abs(hitX - rd) + abs(rd - cx)) {
      int nt = abs(rd - cx);
      if (nt != 0) times.push_back(make_pair(nt, 1));
    }
    if (abs(hitY - cy) == abs(hitY - cd) + abs(cd - cy)) {
      int nt = abs(cd - cy);
      if (nt != 0) times.push_back(make_pair(nt, 1));
    }
    set<pair<int, int> > tms;
    for (auto p : times) tms.insert(p);
    times.clear();
    for (auto p : tms) times.push_back(p);
    pair<long long int, long long int> cur = make_pair(0ll, 1ll);
    for (int i = 1; i < times.size(); i++) {
      if (times[i].second)
        cur = composite(cur, make_pair(times[i].first - times[i - 1].first, p));
      else
        cur = composite(cur, make_pair(times[i].first - times[i - 1].first, 1));
    }
    st.push_back(cur);
    cx = hitX;
    cy = hitY;
    dx = ndx;
    dy = ndy;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  cin >> ttt;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
