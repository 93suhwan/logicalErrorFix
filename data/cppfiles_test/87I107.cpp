#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v(m);
    vector<int> c(m);
    for (int j = 0; j < m; j++) {
      cin >> v[j].first;
      v[j].second = j;
      c[j] = v[j].first;
    }
    map<int, int> ma;
    sort(v.begin(), v.end());
    int index = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
      ma[it->first] = index;
      index++;
    }
    int ans = 0;
    vector<int> a(m, -1);
    for (auto it = c.begin(); it != c.end(); it++) {
      int j = 0, ind = 0;
      for (j = 0; j < ma[*it]; j++) {
        if (a[j] != -1) {
          ans++;
          if (a[j] == *it) {
            ind++;
            ans--;
            break;
          }
        }
      }
      a[j - ind] = *it;
    }
    cout << ans << "\n";
  }
  return 0;
}
