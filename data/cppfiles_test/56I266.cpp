#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long N = 3e5 + 100, M = 6e5 + 100, Q = 5e5 + 100, K = 20, INF = 1e18,
                MOD = 1e9 + 7;
long long t, x, y;
pair<long long, long long> dd[] = {{0, 1},  {1, 1},   {1, 0},  {1, -1},
                                   {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
string e;
void go(long long q, long long w) {
  if (q == x && w == y) return;
  x = q;
  y = w;
  cout << q << " " << w << endl;
  string s;
  cin >> s;
  e = s;
}
pair<long long, long long> ff(string s) {
  if (s == "Right") return dd[0];
  if (s == "Left") return dd[4];
  if (s == "Up") return dd[6];
  if (s == "Down") return dd[2];
  if (s == "Down-Right") return dd[1];
  if (s == "Down-Left") return dd[3];
  if (s == "Up-Left") return dd[5];
  if (s == "Up-Right") return dd[7];
  return {0, 0};
}
long long fx(string s) {
  if (s == "Right") return dd[0].first;
  if (s == "Left") return dd[4].first;
  if (s == "Up") return dd[6].first;
  if (s == "Down") return dd[2].first;
  if (s == "Down-Right") return dd[1].first;
  if (s == "Down-Left") return dd[3].first;
  if (s == "Up-Left") return dd[5].first;
  if (s == "Up-Right") return dd[7].first;
  return 0;
}
long long fy(string s) {
  if (s == "Right") return dd[0].second;
  if (s == "Left") return dd[4].second;
  if (s == "Up") return dd[6].second;
  if (s == "Down") return dd[2].second;
  if (s == "Down-Right") return dd[1].second;
  if (s == "Down-Left") return dd[3].second;
  if (s == "Up-Left") return dd[5].second;
  if (s == "Up-Right") return dd[7].second;
  return 0;
}
void solve() {
  cin >> t;
  while (t-- > 0) {
    x = 2, y = 1;
    go(x, y);
    if (e == "Done") {
      continue;
    }
    long long dir = 1;
    bool fl = false;
    while (e != "Done") {
      if (e == "Down" || e == "Down-Right" || e == "Down-Left") {
        go(x + 1, y);
        if (e == "Done") break;
        go(x, 1);
        dir = 1;
        fl = false;
        continue;
      }
      if (e == "Up" || e == "Up-Left" || e == "Up-Right") {
        go(x, 1);
        dir = 1;
        fl = true;
        continue;
      }
      if (dir == 1) {
        if (y == 8) {
          if (fl) {
            fl = false;
            go(x, y - 1);
          } else {
            go(x + 1, y);
          }
          dir = 0;
        } else {
          go(x, y + 1);
        }
      } else {
        if (y == 1) {
          if (fl) {
            fl = false;
            go(x, y + 1);
          } else {
            go(x + 1, y);
          }
          dir = 1;
        } else {
          go(x, y - 1);
        }
      }
    }
  }
}
