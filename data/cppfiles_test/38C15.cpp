#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      A[i][j] = s[j] == '.';
    }
  }
  vector<int> not_valid(m, 0);
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 1; j < m; j++) {
      if (!A[i][j] && !A[i + 1][j - 1]) {
        not_valid[j] = 1;
      }
    }
  }
  vector<int> prefix(m);
  prefix[0] = not_valid[0];
  for (int i = 1; i < m; i++) {
    prefix[i] = prefix[i - 1] + not_valid[i];
  }
  function<bool(int, int)> qry = [&](int a, int b) {
    return prefix[b] - prefix[a] == 0;
  };
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (qry(a, b)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
