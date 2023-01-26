#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long N = 2e7 + 10;
const long double PI = acos(-1);
using namespace std;
inline void judge() {
  long long n;
  cin >> n;
  vector<pair<long long, pair<long long, long long>>> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].second.first;
    v[i].second.second = i;
  }
  string s;
  cin >> s;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1') v[i].first = 1;
  }
  sort(v.begin(), v.end());
  vector<long long> ans(n);
  for (long long i = 0; i < n; i++) {
    ans[v[i].second.second] = i;
  }
  for (auto i : ans) cout << i + 1 << ' ';
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    judge();
  }
  return 0;
}
