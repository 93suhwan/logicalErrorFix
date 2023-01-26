#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
void YES(bool t = true) { cout << (t ? "YES" : "NO") << endl; }
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const long long inf = 1000000001;
const long long INF = (long long)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(long long t) { return __builtin_popcountll(t); }
vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
struct Setup_io {
  Setup_io() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(25);
  }
} setup_io;
const long long MOD = 998244353;
void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < (int)(h); i++) {
    cin >> s[i];
  }
  vector<vector<int>> sum(h + 1, vector<int>(w + 1));
  for (int i = 0; i < (int)(h); i++) {
    for (int j = 0; j < (int)(w); j++) {
      sum[i + 1][j + 1] = sum[i + 1][j] + (s[i][j] - '0');
    }
  }
  for (int i = 0; i < (int)(h); i++) {
    for (int j = 0; j < (int)(w + 1); j++) {
      sum[i + 1][j] += sum[i][j];
    }
  }
  auto black = [&](int i1, int i2, int j1, int j2) {
    return sum[i2][j2] - sum[i1][j2] - sum[i2][j1] + sum[i1][j1];
  };
  auto white = [&](int i1, int i2, int j1, int j2) {
    return (i2 - i1) * (j2 - j1) - black(i1, i2, j1, j2);
  };
  int ans = 16;
  for (int i1 = 1; i1 < h; i1++) {
    for (int i2 = i1 + 3; i2 < h; i2++) {
      for (int j1 = 1; j1 < w; j1++) {
        int kaku = white(i1, i2, j1 - 1, j1);
        for (int j2 = j1 + 1; j2 < w; j2++) {
          int kaku_add = black(i1, i2, j2 - 1, j2);
          kaku_add += white(i1 - 1, i1, j2 - 1, j2);
          kaku_add += white(i2, i2 + 1, j2 - 1, j2);
          kaku += kaku_add;
          if (kaku >= ans) break;
          if (j2 - j1 >= 2) {
            int temp = kaku;
            temp += white(i1, i2, j2, j2 + 1);
            chmin(ans, temp);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
