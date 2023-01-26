#include <bits/stdc++.h>
using namespace std;
double PI = 3.14159265358979323846;
int rx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int ry[8] = {0, -1, 1, 0, -1, 1, 1, -1};
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
double sabc(double a1, double a2, double a3, double b1, double b2, double b3) {
  double g = ((a1 - a3) * (b2 - b3) - (b1 - b3) * (a2 - a3)) / 2;
  return abs(g);
}
int t;
void solve() {
  int m, n;
  cin >> m >> n;
  int p[m + 1][n + 1];
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> p[i][j];
    }
  }
  int l = 0, r = 1e9 + 1, mid;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    map<int, int> col;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[i][j] >= mid) col[j]++;
      }
    }
    set<int> w, o;
    int num = 0;
    for (int i = 1; i <= n; i++) {
      if (col[i]) num++;
      for (int j = 1; j <= m; j++) {
        if (p[j][i] >= mid && col[i] == 1) w.insert(j);
      }
    }
    for (set<int>::iterator it = w.begin(); it != w.end(); it++) {
      for (int i = 1; i <= n; i++) {
        if (p[*it][i] >= mid) o.insert(i);
      }
    }
    if (num == n && w.size() + (n - o.size() != 0) <= n - 1)
      l = mid;
    else
      r = mid;
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) solve();
  return 0;
}
