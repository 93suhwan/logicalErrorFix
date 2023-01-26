#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  set<int> s;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] == '.' && a[i - 1][j] == 'X' && a[i][j - 1] == 'X') {
        s.insert(j);
      }
    }
  }
  set<pair<int, int>> p;
  for (int i = 0; i < m; i++) {
    int t = 0;
    for (int j = i; j < m; j++) {
      if (s.find(j) != s.end() && j != i) t = 1;
      if (t) p.insert({i + 1, j + 1});
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    if (p.find({l, r}) == p.end())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1, l = 1;
  while (t--) {
    solve();
  }
}
