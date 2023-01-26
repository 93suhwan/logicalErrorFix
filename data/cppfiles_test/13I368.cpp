#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n, string(m, ' '));
  for (int x = 0; x < n; x += 2) {
    if (k % (n - x) == 0 && k / (n - x) * 2 <= m &&
        ((n - x) % 2 == 0 || k / (n - x) * 2 == m)) {
      cout << "YES\n";
      int id = 0;
      array<char, 3> p = {'a', 'b', 'c'}, q = {'e', 'f', 'g'};
      for (int i = 0; i < n - x; i++) {
        for (int j = 0; j + 1 < k / (n - x) * 2; j += 2) {
          s[i][j] = s[i][j + 1] = p[id];
          swap(p, q);
        }
        id = (id + 1) % 3;
      }
      p = {'x', 'y', 'z'}, q = {'u', 'v', 'w'};
      for (int j = 0; j < m; j++) {
        for (int i = 0; i + 1 < n; i++) {
          if (s[i][j] == ' ' && s[i + 1][j] == ' ') {
            s[i][j] = s[i + 1][j] = p[id];
            swap(p, q);
            i++;
          }
        }
        id = (id + 1) % 3;
      }
      for (auto i : s) cout << i << '\n';
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
