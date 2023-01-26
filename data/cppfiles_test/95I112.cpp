#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
char buffer[maxn], *S, *T;
inline char Get_Char() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, maxn, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int read() {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f) return -re;
  return re;
}
inline void read(int& x) {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
inline void read(long long& x) {
  char c;
  long long re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
vector<vector<int> > gird, all;
int n, m;
vector<pair<int, pair<int, int> > > val;
const int mxn = 5e5 + 5;
int curp[mxn], curs[mxn];
inline void solve() {
  multiset<int> pre, suf;
  pre.clear(), suf.clear();
  cin >> n >> m;
  all.clear();
  val.clear();
  all.resize(n + 2);
  gird.clear();
  gird.resize(n + 2);
  for (int i = 1; i <= n; ++i) {
    gird[i].resize(m + 2);
    all[i].resize(m + 2);
    for (int j = 1; j <= m; ++j)
      cin >> gird[i][j], val.push_back(make_pair(gird[i][j], make_pair(i, j)));
  }
  sort(val.begin(), val.end());
  for (int i = 1; i <= n; ++i) curp[i] = 0, curs[i] = m + 1;
  for (int ee = 0; ee < val.size(); ++ee) {
    int cv;
    int x = val[ee].second.first, y = val[ee].second.second, v = val[ee].first;
    cv = v;
    for (; ee < val.size() and val[ee].first == cv; ++ee) {
      x = val[ee].second.first, y = val[ee].second.second, v = val[ee].first;
      all[x][y] = 1;
      if (curp[x] > 0) pre.erase(pre.find(curp[x]));
      for (int i = curp[x]; i <= m; ++i) {
        if (all[x][i + 1]) {
          ++curp[x];
        } else
          break;
      }
      if (curp[x] > 0) pre.insert(curp[x]);
      if (curs[x] <= m) suf.erase(suf.find(curs[x]));
      for (int i = curs[x]; i; --i) {
        if (all[x][i - 1]) {
          --curs[x];
        } else
          break;
      }
      if (curs[x] <= m) suf.insert(curs[x]);
      if (curp[x] > 0 and curs[x] <= m) {
        cout << "NO\n";
        return;
      }
    }
    --ee;
    if (pre.size() and suf.size()) {
      if ((int)(pre.size()) + (int)(suf.size()) == n) {
        int bg, ed, f;
        bg = (*pre.begin());
        auto at = pre.end();
        --at;
        ed = *at;
        f = bg;
        if (bg == ed) {
          bg = (*suf.begin());
          at = suf.end();
          --at;
          ed = *at;
          if (bg == ed and f + 1 == bg) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
              if (curp[i])
                cout << 'B';
              else
                cout << 'R';
            }
            cout << ' ' << f << '\n';
            return;
          }
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  T = 1;
  cin >> T;
  for (; T--;) solve();
  return 0;
}
