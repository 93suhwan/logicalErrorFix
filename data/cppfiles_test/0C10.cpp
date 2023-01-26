#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> a(n);
  string s;
  for (int j = 0; j < n; ++j) {
    cin >> s;
    for (int i = 0; i < m; ++i)
      if (i % 2) s[i] = (char)('Z' - s[i]);
    a[j] = make_pair(s, j + 1);
  }
  stable_sort(a.begin(), a.end());
  for (int j = 0; j < n; ++j) {
    cout << a[j].second << ' ';
  }
}
