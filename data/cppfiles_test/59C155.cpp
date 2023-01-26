#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long mod = 1e9 + 7;
const long long linf = 1e18;
const double EPS = 1e-10;
const double pi = acos(-1);
template <class T>
void chmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
void chmax(T& x, T y) {
  if (x < y) x = y;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int st[2][2] = {};
      for (int k = 0; k < n; k++) {
        st[a[k][i]][a[k][j]]++;
      }
      if (st[0][0] != 0) continue;
      if (st[1][0] <= n / 2 && st[0][1] <= n / 2) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
