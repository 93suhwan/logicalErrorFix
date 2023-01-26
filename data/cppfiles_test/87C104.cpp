#include <bits/stdc++.h>
#pragma GCC optimization("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    vector<int> orig;
    for (int i = 0; i < m; i++) {
      int a;
      cin >> a;
      orig.push_back(a);
      v.push_back({a, -i});
    }
    sort(v.begin(), v.end());
    vector<int> rank(m);
    for (int i = 0; i < m; i++) rank[-v[i].second] = i;
    int ans = 0;
    vector<int> s;
    for (int i = 0; i < m; i++) {
      int pos = rank[i];
      for (int i = 0; i < s.size(); i++) {
        if (pos > s[i]) ans++;
      }
      s.push_back(pos);
    }
    cout << ans << "\n";
    t--;
  }
}
