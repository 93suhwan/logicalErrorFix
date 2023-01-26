#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<pair<string, int> > v;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    v.push_back({x, i + 1});
  }
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      continue;
    } else {
      for (int j = 0; j < n; j++) {
        char c = v[j].first[i];
        c = 155 - c;
        v[j].first[i] = c;
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
  return 0;
}
