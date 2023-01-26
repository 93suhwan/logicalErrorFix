#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> f(n);
  for (int i = 0; i < n; ++i) {
    cin >> f[i];
  }
  vector<int> v(m + 1);
  for (int j = 1; j < m; ++j) {
    for (int i = 1; i < n; ++i) {
      if (f[i - 1][j] == 'X' && f[i][j - 1] == 'X') {
        v[j] = 1;
      }
    }
  }
  for (int i = 1; i < m + 1; ++i) {
    v[i] += v[i - 1];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    if (v[b] - v[a - 1] > 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
