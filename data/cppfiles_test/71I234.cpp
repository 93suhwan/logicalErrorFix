#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 200005, INF = 1000000009;
struct ban {
  int x, y;
};
bool operator<(const ban& a, const ban& b) {
  return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
double dist(const ban& a, const ban& b) {
  return sqrt((a.x - b.x) * 1LL * (a.x - b.x) +
              (a.y - b.y) * 1LL * (a.y - b.y));
}
long long F(const ban& t1, const ban& t2, const ban& t) {
  return (t.x - t1.x) * 1LL * (t2.y - t1.y) -
         (t.y - t1.y) * 1LL * (t2.x - t1.x);
}
int n, k;
ban a[N];
bool so(int i, int j) { return a[i] < a[j]; }
bool c[N];
double dp[(1 << 17)][17];
double solv() {
  int u = -1;
  for (int i = 1; i <= 3; ++i) {
    for (int j = i + 1; j <= 3; ++j) {
      int q = 0;
      for (int k = 1; k <= n; ++k) {
        if (F(a[i], a[j], a[k])) ++q;
      }
      if (q == 1) {
        for (int k = 1; k <= n; ++k) {
          if (F(a[i], a[j], a[k])) {
            u = k;
            break;
          }
        }
      }
    }
  }
  assert(u != -1);
  c[u] = true;
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    if (i == u) continue;
    v.push_back(i);
  }
  sort((v).begin(), (v).end(), so);
  c[v[0]] = true;
  c[v[1]] = true;
  c[v.back()] = true;
  c[v[((int)(v).size()) - 2]] = true;
  double minu = INF;
  int mini = -1;
  for (int i = 0; i < ((int)(v).size()); ++i) {
    if (dist(a[u], a[v[i]]) < minu) {
      minu = dist(a[u], a[v[i]]);
      mini = i;
    }
  }
  for (int i = max(0, mini - 3); i <= min(((int)(v).size()) - 1, mini + 3);
       ++i) {
    c[v[i]] = true;
  }
  for (int i = 0; i < ((int)(v).size()); ++i) {
    if (v[i] == k) {
      for (int j = max(0, i - 1); j <= min(((int)(v).size()) - 1, i + 1); ++j) {
        c[v[j]] = true;
      }
      break;
    }
  }
  v.clear();
  for (int i = 1; i <= n; ++i) {
    if (c[i]) v.push_back(i);
  }
  for (int x = 0; x < (1 << ((int)(v).size())); ++x)
    for (int i = 0; i < ((int)(v).size()); ++i) dp[x][i] = INF;
  for (int i = 0; i < ((int)(v).size()); ++i) {
    if (v[i] == k) dp[(1 << i)][i] = 0;
  }
  for (int x = 0; x < (1 << ((int)(v).size())); ++x) {
    for (int i = 0; i < ((int)(v).size()); ++i) {
      if (dp[x][i] == INF) continue;
      for (int j = 0; j < ((int)(v).size()); ++j) {
        if (!(x & (1 << j))) {
          dp[(x | (1 << j))][j] =
              min(dp[(x | (1 << j))][j], dp[x][i] + dist(a[v[i]], a[v[j]]));
        }
      }
    }
  }
  double ans = INF;
  for (int i = 0; i < ((int)(v).size()); ++i)
    ans = min(ans, dp[(1 << ((int)(v).size())) - 1][i]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(9);
  int tt = 1;
  while (tt--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    set<pair<int, int> > s;
    c[k] = true;
    s.insert(make_pair(a[k].x, a[k].y));
    for (int i = 1; i <= n; ++i) {
      if (s.find(make_pair(a[i].x, a[i].y)) != s.end()) continue;
      c[i] = true;
      s.insert(make_pair(a[i].x, a[i].y));
    }
    vector<ban> v;
    bool z = false;
    for (int i = 1; i <= n; ++i) {
      if (c[i]) {
        c[i] = false;
        v.push_back(a[i]);
        if (i == k && z == false) {
          z = true;
          k = ((int)(v).size());
        }
      }
    }
    n = ((int)(v).size());
    for (int i = 1; i <= n; ++i) a[i] = v[i - 1];
    cout << solv() << "\n";
  }
  return 0;
}
