#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.second == b.second) return (a.first < b.first);
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    map<pair<int, int>, int> m;
    for (int ol = 0; ol < n; ol++) {
      int l, r;
      cin >> l >> r;
      v.push_back(make_pair(l, r));
    }
    sort(v.begin(), v.end());
    if (n == 1) {
      cout << 1 << " " << 1 << " " << 1 << endl;
      continue;
    }
    for (int i = 0; i < n - 1; i++) {
      if (v[i].first == v[i + 1].first) {
        cout << v[i].first << " " << v[i + 1].second << " " << v[i].second + 1
             << endl;
        m[make_pair(v[i].first, v[i + 1].second)] = -1;
      }
      if (v[i].first == v[i].second)
        cout << v[i].first << " " << v[i].first << " " << v[i].first << endl,
            m[make_pair(v[i].first, v[i].second)] = -1;
      ;
    }
    sort(v.begin(), v.end(), sortbysec);
    for (int i = 0; i < n; i++) {
      if (v[i].second == v[i + 1].second) {
        if (m[make_pair(v[i].first, v[i].second)] != -1)
          cout << v[i].first << " " << v[i].second << " " << v[i + 1].first - 1
               << endl;
      }
    }
  }
}
