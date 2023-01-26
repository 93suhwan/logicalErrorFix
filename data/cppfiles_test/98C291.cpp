#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> m;
    for (long long int i = 0; i < s.size(); i++) {
      m[s[i]] = (i + 1);
    };
    string g;
    cin >> g;
    long long int n = g.size(), ans = 0;
    for (long long int i = 0; i < n - 1; i++) {
      ans += abs(m[g[i]] - m[g[i + 1]]);
    }
    cout << ans << "\n";
  }
  return 0;
}
