#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i].first = s;
    v[i].second = i + 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j % 2 == 1) {
        v[i].first[j] = (char)('Z' - v[i].first[j]);
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
  return 0;
}
