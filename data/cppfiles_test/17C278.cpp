#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  return (b < a) ? (a = b, 1) : 0;
}
using ll = long long;
using R = long double;
const R EPS = 1e-9L;
inline int sgn(const R &r) { return (r > EPS) - (r < -EPS); }
inline R sq(R x) { return sqrt(max(x, 0.0L)); }
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const pid_t pid = getpid();
int ary[50010][5];
int main(void) {
  int t;
  cin >> t;
  for (int loop = int(0); loop < int(t); ++loop) {
    int n;
    cin >> n;
    for (int i = int(0); i < int(n); ++i)
      for (int j = int(0); j < int(5); ++j) {
        cin >> ary[i][j];
      }
    int best = 0;
    for (int i = int(0); i < int(n); ++i) {
      int cnt = 0;
      for (int j = int(0); j < int(5); ++j) {
        if (ary[i][j] < ary[best][j]) {
          cnt++;
        }
      }
      if (cnt >= 3) {
        best = i;
      }
    }
    int ans = -1;
    bool ok = true;
    for (int i = int(0); i < int(n); ++i) {
      int cnt = 0;
      if (i == best) {
        continue;
      }
      for (int j = int(0); j < int(5); ++j) {
        if (ary[best][j] < ary[i][j]) {
          cnt++;
        }
      }
      if (cnt < 3) {
        ok = false;
      }
    }
    if (ok) {
      ans = best + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
