#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> s(n + 1);
  for (int i = 0; i < (int)m + 1; i++) s[0] += '.';
  for (int i = 0; i < (int)n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }
  vector<int> sum(m + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1][j] == 'X' and s[i][j - 1] == 'X') sum[j]++;
    }
  }
  for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << (sum[y] - sum[x] == 0 ? "YES" : "NO") << endl;
  }
  return 0;
}
