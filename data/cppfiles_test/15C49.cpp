#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)2.01e18;
const double PI = acos((double)-1);
constexpr int popcnt(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int pow2(int x) { return 1 << x; }
constexpr int mask2(int x) { return pow2(x) - 1; }
inline namespace FileIO {
void setPrec() { cout << fixed << setprecision(15); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIn(string second) { freopen(second.c_str(), "r", stdin); }
void setOut(string second) { freopen(second.c_str(), "w", stdout); }
void setIO(string second = "") {
  unsyncIO();
  setPrec();
  if (second.length()) setIn(second + ".in"), setOut(second + ".out");
}
}  // namespace FileIO
int main() {
  setIO();
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<pair<int, int>>> mark(n, vector<pair<int, int>>(m, {0, 0}));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == '.')
          grid[i][j] = 0;
        else
          grid[i][j] = 1;
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) mark[i][j] = {1, 1};
      }
    vector<pair<int, int>> ids;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!grid[i][j]) continue;
        if (j > 0 && mark[i - 1][j - 1].first)
          mark[i][j].first = mark[i - 1][j - 1].first + 1;
        if (j + 1 < m && mark[i - 1][j + 1].second)
          mark[i][j].second = mark[i - 1][j + 1].second + 1;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        int itr = min(mark[i][j].first, mark[i][j].second);
        if (itr < k + 1) continue;
        for (int x = 0; x < itr; x++) {
          grid[i - x][j - x] = 0;
          grid[i - x][j + x] = 0;
        }
      }
    }
    bool yes = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          yes = false;
          break;
        }
      }
      if (!yes) {
        break;
      }
    }
    cout << (yes ? "YES\n" : "NO\n");
  }
  return 0;
}
