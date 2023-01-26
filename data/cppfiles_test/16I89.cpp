#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    map<long long int, vector<long long int>> m;
    for (long long int i = 0; i < n; i++) {
      m[s[i]].push_back(i);
    }
    long long int k = 0;
    long long int ans = 0;
    for (auto x : m) {
      for (long long int i = 0; i < x.second.size(); i++) {
        if (x.second[i] != k) {
          ans++;
        }
        k++;
      }
    }
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
