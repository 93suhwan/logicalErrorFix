#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(26, 0));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> c(26, 0);
    for (int j = 0; j < (int)s.size(); j++) {
      c[s[j] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      v[i][j] = 2 * c[j] - (int)s.size();
    }
  }
  vector<int> k;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < n; j++) {
      k.push_back(v[j][i]);
    }
    sort(k.rbegin(), k.rend());
    long long int sum = 0;
    for (int j = 0; j < n; j++) {
      if (sum + k[j] > 0) {
        sum += k[j];
        ans = max(ans, j + 1);
      } else {
        break;
      }
    }
    k.clear();
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
