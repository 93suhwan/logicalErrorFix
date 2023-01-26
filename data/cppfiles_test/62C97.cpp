#include <bits/stdc++.h>
using namespace std;
template <typename T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d) {
  return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d) {
  return min(min(a, d), min(b, c));
}
template <typename T>
T binex(T a, T b, T mod) {
  T ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, multiset<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T, class Q>
ostream &operator<<(ostream &os, pair<T, Q> a) {
  os << "| ";
  os << a.first << ", " << a.second << " ";
  return os << "|";
}
template <class P, class Q, class T>
ostream &operator<<(ostream &os, tuple<P, Q, T> a) {
  os << "| " << (get<0>(a)) << ", " << (get<1>(a)) << ", " << (get<2>(a))
     << "|";
  return os;
}
void precomp() {}
void upd(vector<vector<pair<int64_t, int64_t>>> &dp, vector<vector<int64_t>> &a,
         int64_t x, int64_t y, int64_t &ans) {
  if (x < 0 || y < 0) {
    return;
  }
  if (a[x][y] == 1) {
    dp[x][y].first = 0;
    dp[x][y].second = 0;
    return;
  }
  ans -= dp[x][y].first + dp[x][y].second + 1;
  if (y + 1 >= dp[0].size()) {
    dp[x][y].first = 0;
  } else {
    dp[x][y].first = dp[x][y + 1].second;
    if (a[x][y + 1] == 0) {
      dp[x][y].first++;
    }
  }
  if (x + 1 >= dp.size()) {
    dp[x][y].second = 0;
  } else {
    dp[x][y].second = dp[x + 1][y].first;
    if (a[x + 1][y] == 0) {
      dp[x][y].second++;
    }
  }
  ans += dp[x][y].first + dp[x][y].second + 1;
}
void solve() {
  int64_t n, m, q;
  cin >> n >> m >> q;
  vector<vector<int64_t>> a(n, vector<int64_t>(m));
  vector<vector<pair<int64_t, int64_t>>> dp(n,
                                            vector<pair<int64_t, int64_t>>(m));
  int64_t ans = 1;
  dp[n - 1][m - 1] = {0, 0};
  for (int64_t i = m - 2; i >= 0; i--) {
    dp[n - 1][i] = {1, 0};
    ans += 2;
  }
  for (int64_t i = n - 2; i >= 0; i--) {
    dp[i][m - 1] = {0, 1};
    ans += 2;
  }
  for (int64_t i = n - 2; i >= 0; i--) {
    for (int64_t j = m - 2; j >= 0; j--) {
      dp[i][j].first = (dp[i][j + 1].second + 1);
      dp[i][j].second = (dp[i + 1][j].first + 1);
      ans += dp[i][j].first + dp[i][j].second + 1;
    }
  }
  for (int64_t i = 0; i < q; i++) {
    int64_t x, y;
    cin >> x >> y;
    x--;
    y--;
    a[x][y] ^= 1;
    if (a[x][y] == 0) {
      if (y + 1 < m && a[x][y + 1] == 0) {
        dp[x][y].first = dp[x][y + 1].second + 1;
      } else {
        dp[x][y].first = 0;
      }
      if (x + 1 < n && a[x + 1][y] == 0) {
        dp[x][y].second = dp[x + 1][y].first + 1;
      } else {
        dp[x][y].second = 0;
      }
      ans += dp[x][y].first + dp[x][y].second + 1;
    } else {
      ans -= dp[x][y].first + dp[x][y].second + 1;
      dp[x][y].first = 0;
      dp[x][y].second = 0;
    }
    while (x >= 0 && y >= 0) {
      upd(dp, a, x - 1, y, ans);
      upd(dp, a, x, y - 1, ans);
      upd(dp, a, x - 1, y - 1, ans);
      x--;
      y--;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t T;
  T = 1;
  precomp();
  for (int64_t I = 1; I <= T; I++) {
    solve();
  }
}
