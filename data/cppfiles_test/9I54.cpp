#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
  cout << "YES\n";
  return;
}
void no() {
  cout << "NO\n";
  return;
}
template <class T>
void out(T temp) {
  cout << temp << endl;
  return;
}
void out(double temp) {
  cout << setprecision(7) << fixed << temp << endl;
  return;
}
void out(long double temp) {
  cout << setprecision(7) << fixed << temp << endl;
  return;
}
const int mxN = 1e3 + 1;
int a[mxN][mxN];
bool clear[mxN];
void init() {}
void solve(int case_no) {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  while (q--) {
    pair<int, int> cur;
    cin >> cur.second;
    if (clear[cur.second]) {
      cout << cur.second << ' ';
      continue;
    }
    cur.first = 1;
    bool changed = false;
    while (cur.first != n) {
      if (a[cur.first][cur.second] == 1) {
        a[cur.first][cur.second] = 2;
        changed = true;
        cur.second++;
      } else if (a[cur.first][cur.second] == 2) {
        a[cur.first][cur.second] = 2;
        cur.first++;
      } else if (a[cur.first][cur.second] == 3) {
        a[cur.first][cur.second] = 2;
        changed = true;
        cur.second--;
      }
    }
    cout << cur.second << " ";
    if (!changed) clear[cur.second] = true;
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  init();
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
}
