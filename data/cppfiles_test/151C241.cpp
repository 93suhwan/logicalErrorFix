#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n;
  cin >> n;
  map<long long int, long long int> m;
  vector<long long int> a(n);
  vector<pair<long long int, long long int>> b(n);
  vector<long long int> ans;
  for (long long int i = 0; i < n; ++i) {
    long long int o;
    cin >> o;
    if (o == 1) {
      long long int x;
      cin >> x;
      a[i] = x;
      m[x] = x;
    } else {
      a[i] = 0;
      long long int x, y;
      cin >> x >> y;
      b[i].first = x;
      b[i].second = y;
      m[y] = y;
    }
  }
  for (long long int i = n - 1; i >= 0; --i) {
    if (a[i] == 0) {
      m[b[i].first] = m[b[i].second];
    } else {
      ans.push_back(m[a[i]]);
    }
  }
  for (auto i = ans.rbegin(); i != ans.rend(); ++i) cout << *i << " ";
}
