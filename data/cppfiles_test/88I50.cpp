#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<pair<long long int, long long int>> v;
    map<long long int, long long int> mp;
    for (long long int i = 0; i < m; i++) {
      long long int x;
      cin >> x;
      mp[x]++;
      v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    vector<long long int> visited(m, 0);
    long long int ans = 0;
    for (long long int i = 1; i <= m; i++) {
      for (long long int j = 0; j < m; j++) {
        if (v[j].second == i) {
          visited[j] = 1;
          break;
        }
        if (visited[j] != 0) {
          ans++;
        }
      }
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second > 1) {
        long long int x = it->second;
        long long int y = (x * (x - 1)) / 2;
        ans -= y;
      }
    }
    cout << ans << "\n";
  }
}
