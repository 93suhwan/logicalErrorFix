#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int i, p, j, n, m;
  cin >> n >> m;
  string s[n];
  char q = 'A';
  vector<pair<string, int>> v;
  for (i = 0; i < n; i++) cin >> s[i];
  for (i = 0; i < n; i++) {
    for (j = 1; j < m; j += 2) {
      p = s[i][j] - 'A';
      p = 25 - p;
      q += p;
      s[i][j] = q;
      q = 'A';
    }
  }
  for (i = 0; i < n; i++) v.push_back(make_pair(s[i], i + 1));
  sort(v.begin(), v.end());
  for (i = 0; i < n; i++) cout << v[i].second << " ";
  return 0;
}
