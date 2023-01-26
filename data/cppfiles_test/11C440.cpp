#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, pair<long long int, long long int>>& a,
         pair<string, pair<long long int, long long int>>& b) {
  return a.second.first > b.second.first;
}
void solve() {
  vector<string> v;
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  string t = "abcde";
  long long int ans = 0;
  for (long long int k = 0; k < 5; k++) {
    vector<pair<string, pair<long long int, long long int>>> vec;
    for (long long int i = 0; i < n; i++) {
      string s = v[i];
      long long int len = s.length();
      long long int freq = 0;
      for (long long int j = 0; j < len; j++) {
        if (s[j] == t[k]) freq++;
      }
      vec.push_back({s, {2 * freq - len, freq}});
    }
    sort(vec.begin(), vec.end(), cmp);
    long long int tot1 = 0;
    long long int tot2 = 0;
    long long int temp = 0;
    for (long long int i = 0; i < n; i++) {
      string s = vec[i].first;
      long long int flag = vec[i].second.second;
      if (tot2 + flag > tot1 + s.length() - flag) {
        temp++;
        ans = max(ans, temp);
        tot2 += flag;
        tot1 += s.length() - flag;
      }
    }
  }
  cout << ans << "\n";
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _t;
  cin >> _t;
  while (_t--) solve();
}
