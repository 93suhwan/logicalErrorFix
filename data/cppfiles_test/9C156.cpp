#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int n = s.size();
  map<char, long long int> r;
  for (long long int i = 0; i < n; i++) {
    r[s[i]]++;
  }
  long long int k = 0, cnt = 0;
  for (auto it = r.begin(); it != r.end(); it++) {
    if (it->second >= 2)
      k++;
    else if (it->second == 1)
      cnt++;
  }
  cout << k + cnt / 2 << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i < t + 1; i++) {
    solve();
  }
  return 0;
}
