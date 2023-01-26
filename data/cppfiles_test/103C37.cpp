#include <bits/stdc++.h>
using namespace std;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using s8 = int8_t;
using s16 = int16_t;
using s32 = int32_t;
using s64 = int64_t;
using ld = long double;
const int maxn = 2000;
int n, m;
char p[maxn][maxn];
int dp[maxn][maxn];
vector<pair<short, short>> path;
int f(short i, short j) {
  path.push_back(make_pair(i, j));
  bool run = true;
  int cnt;
  while (run) {
    int i = path.back().first;
    int j = path.back().second;
    if (i < 0 || i == n || j < 0 || j == m || p[i][j] == '#') {
      run = false;
      cnt = 0;
      break;
    } else {
      if (dp[i][j] != -1) {
        run = false;
        cnt = dp[i][j];
        break;
      }
      if (p[i][j] == 'R') {
        path.push_back(make_pair(i, j + 1));
      } else if (p[i][j] == 'L') {
        path.push_back(make_pair(i, j - 1));
      } else if (p[i][j] == 'U') {
        path.push_back(make_pair(i - 1, j));
      } else {
        path.push_back(make_pair(i + 1, j));
      }
    }
  }
  path.pop_back();
  while (!path.empty()) {
    int i = path.back().first;
    int j = path.back().second;
    path.pop_back();
    dp[i][j] = ++cnt;
  }
  return cnt;
}
char vis[maxn][maxn];
void build(short i, short j) {
  path.push_back(make_pair(i, j));
  while (true) {
    short i = path.back().first;
    short j = path.back().second;
    if (i < 0 || i == n || j < 0 || j == m || vis[i][j] == 'R') {
      path.pop_back();
      break;
    } else {
      if (vis[i][j] == 'G') {
        int len = 1;
        for (int it = path.size() - 2; it >= 0 && path[it] != make_pair(i, j);
             it--) {
          len++;
        }
        for (int it = path.size() - 2; it >= 0; it--) {
          dp[path[it].first][path[it].second] = len;
          if (path[it] == make_pair(i, j)) {
            break;
          }
        }
        break;
      }
      vis[i][j] = 'G';
      if (p[i][j] == 'R') {
        path.push_back(make_pair(i, j + 1));
      } else if (p[i][j] == 'L') {
        path.push_back(make_pair(i, j - 1));
      } else if (p[i][j] == 'U') {
        path.push_back(make_pair(i - 1, j));
      } else {
        path.push_back(make_pair(i + 1, j));
      }
    }
  }
  while (!path.empty()) {
    int i = path.back().first;
    int j = path.back().second;
    path.pop_back();
    vis[i][j] = 'R';
  }
}
void solve(istream& cin, ostream& cout) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> p[i][j];
      dp[i][j] = -1;
      vis[i][j] = '?';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      build(i, j);
    }
  }
  int bi = 0, bj = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (f(i, j) > f(bi, bj)) {
        bi = i;
        bj = j;
      }
    }
  }
  cout << bi + 1 << " " << bj + 1 << " " << f(bi, bj) << "\n";
}
void main_build() {}
void correct_solve(istream& cin, ostream& cout) {}
int main() {
  ios::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
  main_build();
  s64 t = 1;
  cin >> t;
  while (t--) {
    solve(cin, cout);
  }
  return 0;
}
