#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e5 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool chkmin(T& x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
bool chkmax(T& x, T y) {
  return y > x ? x = y, 1 : 0;
}
int n, k;
struct mine {
  int x, y, t, id;
} a[N];
bool operator<(const mine& a, const mine& b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
map<int, vector<mine>> r, c;
int fa[N];
int minn[N];
int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
void merge(int u, int v) {
  u = getfa(u);
  v = getfa(v);
  chkmin(minn[u], minn[v]);
  fa[v] = u;
}
void main0() {
  int T;
  cin >> T;
  while (T--) {
    r.clear();
    c.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      int x, y, t;
      cin >> x >> y >> t;
      a[i] = {x, y, t, i};
      r[x].push_back(a[i]);
      c[y].push_back(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      fa[i] = i;
      minn[i] = a[i].t;
    }
    for (auto [rowid, v] : r) {
      sort((v).begin(), (v).end());
      for (int i = 1; i <= ((int)(v).size()) - 1; ++i) {
        if (v[i].y - v[i - 1].y <= k) merge(v[i].id, v[i - 1].id);
      }
    }
    for (auto [columnid, v] : c) {
      sort((v).begin(), (v).end());
      for (int i = 1; i <= ((int)(v).size()) - 1; ++i) {
        if (v[i].x - v[i - 1].x <= k) merge(v[i].id, v[i - 1].id);
      }
    }
    vector<int> time;
    for (int i = 1; i <= n; ++i) {
      if (fa[i] == i) time.push_back(minn[i]);
    }
    sort((time).begin(), (time).end(), greater<int>());
    int p = 0;
    while ((p + 1 <= ((int)(time).size()) - 1) && (time[p + 1] >= p + 1)) p++;
    cout << p << endl;
  }
}
