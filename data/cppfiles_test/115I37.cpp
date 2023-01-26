#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long expmod(long long a, long long b, int m) {
  int res = 1;
  a = a % m;
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int deadrows = 0;
  int deadcolumns = 0;
  int freerows = n;
  int freecolumns = m;
  vector<set<pair<int, int>>> rowentries(n);
  vector<set<pair<int, int>>> columnentries(m);
  vector<vector<int>> rowvals(n, {0, 0});
  vector<vector<int>> columnvals(m, {0, 0});
  vector<int> checkers = {0, 0};
  while (k--) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    for (int k = 0; k < 2; k++) {
      if (rowentries[x].find({y, k}) != rowentries[x].end()) {
        checkers[(x + y + k) % 2]--;
        rowentries[x].erase({y, k});
        columnentries[y].erase({x, k});
        rowvals[x][(y + k) % 2]--;
        if (rowvals[x][(y + k) % 2] == 0) {
          if (rowvals[x][(y + k + 1) % 2]) {
            deadrows--;
          } else {
            freerows++;
          }
        }
        columnvals[y][(x + k) % 2]--;
        if (columnvals[y][(x + k) % 2] == 0) {
          if (columnvals[x][(y + k + 1) % 2]) {
            deadcolumns--;
          } else {
            freecolumns++;
          }
        }
      }
    }
    if (z != -1) {
      checkers[(x + y + z) % 2]++;
      rowentries[x].insert({y, z});
      columnentries[y].insert({x, z});
      if (rowvals[x][(y + z) % 2] == 0) {
        if (rowvals[x][(y + z + 1) % 2]) {
          deadrows++;
        } else {
          freerows--;
        }
      }
      rowvals[x][(y + z) % 2]++;
      if (columnvals[x][(y + z) % 2] == 0) {
        if (columnvals[x][(y + z + 1) % 2]) {
          deadcolumns++;
        } else {
          freecolumns--;
        }
      }
      columnvals[x][(y + z) % 2]++;
    }
    long long ans = 0;
    if (!deadrows) {
      ans += expmod(2, freerows, MOD);
    }
    if (!deadcolumns) {
      ans += expmod(2, freecolumns, MOD);
    }
    for (int i : checkers) {
      if (!i) ans--;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
  }
}
