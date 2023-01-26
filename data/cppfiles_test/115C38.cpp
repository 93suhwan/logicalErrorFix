#include <bits/stdc++.h>
using namespace std;
template <class T>
using v2d = vector<vector<T> >;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 1e6 + 10;
const int maxM = 1e6 + 10;
const long long mod = 998244353;
int n, m, k, cnt_row[maxN][2], cnt_col[maxM][2];
long long power(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) {
      r = r * a % mod;
    }
    b /= 2;
    a = a * a % mod;
  }
  return r;
}
void solve() {
  cin >> n >> m >> k;
  int bad_row = 0, bad_col = 0, parity[2] = {};
  int empty_row = n, empty_col = m;
  map<pair<int, int>, bool> mp;
  while (k--) {
    auto rem = [&](int i, int j) {
      int p = mp[{i, j}];
      parity[p ^ (i & 1) ^ (j & 1)]--;
      int d = p ^ (j & 1) ^ 1;
      mp.erase({i, j});
      bad_row -= (cnt_row[i][0] && cnt_row[i][1]);
      empty_row -= (!cnt_row[i][0] && !cnt_row[i][1]);
      cnt_row[i][d]--;
      bad_row += (cnt_row[i][0] && cnt_row[i][1]);
      empty_row += (!cnt_row[i][0] && !cnt_row[i][1]);
      d = p ^ (i & 1) ^ 1;
      bad_col -= (cnt_col[j][0] && cnt_col[j][1]);
      empty_col -= (!cnt_col[j][0] && !cnt_col[j][1]);
      cnt_col[j][d]--;
      bad_col += (cnt_col[j][0] && cnt_col[j][1]);
      empty_col += (!cnt_col[j][0] && !cnt_col[j][1]);
    };
    auto add = [&](int i, int j, int p) {
      mp[{i, j}] = p;
      parity[p ^ (i & 1) ^ (j & 1)]++;
      int d = p ^ (j & 1) ^ 1;
      bad_row -= (cnt_row[i][0] && cnt_row[i][1]);
      empty_row -= (!cnt_row[i][0] && !cnt_row[i][1]);
      cnt_row[i][d]++;
      bad_row += (cnt_row[i][0] && cnt_row[i][1]);
      empty_row += (!cnt_row[i][0] && !cnt_row[i][1]);
      d = p ^ (i & 1) ^ 1;
      bad_col -= (cnt_col[j][0] && cnt_col[j][1]);
      empty_col -= (!cnt_col[j][0] && !cnt_col[j][1]);
      cnt_col[j][d]++;
      bad_col += (cnt_col[j][0] && cnt_col[j][1]);
      empty_col += (!cnt_col[j][0] && !cnt_col[j][1]);
    };
    int x, y, t;
    cin >> x >> y >> t;
    if (t == -1) {
      if (mp.count({x, y})) {
        rem(x, y);
      }
    } else {
      if (mp.count({x, y})) {
        rem(x, y);
      }
      add(x, y, t);
    }
    long long ans = 0;
    if (!bad_col) {
      ans = (ans + power(2, empty_col)) % mod;
    }
    if (!bad_row) {
      ans = (ans + power(2, empty_row)) % mod;
    }
    if (!parity[0]) {
      ans = (ans - 1 + mod) % mod;
    }
    if (!parity[1]) {
      ans = (ans - 1 + mod) % mod;
    }
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
