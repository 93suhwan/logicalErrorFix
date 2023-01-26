#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e9 + 7;
long long INF = 1000000000000000000;
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int pref[n][5];
    memset(pref, 0, sizeof(pref));
    vector<int> p;
    for (int i = 0; i < n; i++) {
      string y;
      cin >> y;
      p.push_back(y.length());
      for (int j = 0; j < y.length(); j++) pref[i][y[j] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
        v.push_back(2LL * pref[j][i] - p[j]);
      }
      sort(v.rbegin(), v.rend());
      int sum = 0;
      int cnt = 0;
      for (int j = 0; j < v.size(); j++) {
        sum += v[j];
        if (sum <= 0) {
          break;
        } else
          ++cnt;
      }
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
}
