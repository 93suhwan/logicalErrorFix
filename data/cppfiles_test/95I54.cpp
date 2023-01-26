#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 11;
const int MAXN = 1e5 + 5;
const int LG = 20;
const int INF = 1e9;
using ll = long long int;
using ull = unsigned long long int;
const ll MOD2 = 998244353;
const ll MOD1 = 1e9 + 7LL;
template <typename T>
void min_self(T &a, T b) {
  a = min(a, b);
}
template <typename T>
void max_self(T &a, T b) {
  a = max(a, b);
}
ll count(ll m) { return (m * (m + 1)) / 2L; }
ll pow(ll a, ll b) {
  ll r = 1LL;
  while (b) {
    if (b & 1LL) {
      r = r * a;
    }
    a *= a;
    b >>= 1LL;
  }
  return r;
}
ll findLim(ll lim) {
  ll l = 0;
  ll r = LG;
  ll ret = 0;
  while (l <= r) {
    ll m = l + (r - l) / 2L;
    ll p = pow(2L, m);
    if (p >= lim) {
      ret = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ret;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    map<int, vector<int>> cont;
    vector<int> unq_values(n);
    for (int i = 0; i < n; ++i) {
      cont[a[i][0]].emplace_back(i);
      unq_values.emplace_back(a[i][0]);
    }
    sort(unq_values.begin(), unq_values.end());
    unq_values.resize(unique(unq_values.begin(), unq_values.end()) -
                      unq_values.begin());
    ;
    reverse(unq_values.begin(), unq_values.end());
    string coloring = string(n, 'B');
    int red_rows = 0;
    function<bool(int)> verifyRightMatrix = [&](int st) {
      if (st == m) return false;
      int red_max = INT_MIN;
      int blue_min = INT_MAX;
      for (int row = 0; row < n; ++row) {
        for (int col = st; col < m; ++col) {
          if (coloring[row] == 'B') {
            min_self(blue_min, a[row][col]);
          } else {
            max_self(red_max, a[row][col]);
          }
        }
      }
      return blue_min > red_max;
    };
    function<bool(int)> verifyLeftMatrix = [&](int ed) {
      int red_min = INT_MAX;
      int blue_max = INT_MIN;
      for (int row = 0; row < n; ++row) {
        for (int col = 0; col <= ed; ++col) {
          if (coloring[row] == 'B') {
            max_self(blue_max, a[row][col]);
          } else {
            min_self(red_min, a[row][col]);
          }
        }
      }
      return blue_max < red_min;
    };
    unq_values.resize(cont.size() - 1);
    bool ok = false;
    int last_col = 0;
    for (auto row_value : unq_values) {
      cerr << row_value << " \n";
      for (int rowToColor : cont[row_value]) {
        ++red_rows;
        coloring[rowToColor] = 'R';
        for (int col = 1; col < m; ++col) {
          if (row_value == a[rowToColor][col]) {
            max_self(last_col, col);
          }
        }
      }
      if (red_rows == n) break;
      if (verifyLeftMatrix(last_col) && verifyRightMatrix(last_col + 1)) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    } else {
      puts("YES");
      cout << coloring << " " << (last_col + 1) << "\n";
    }
  }
  return 0;
}
