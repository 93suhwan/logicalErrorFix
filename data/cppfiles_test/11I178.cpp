#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<string> v;
  for (long long int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  long long int vec[n + 5][7];
  memset(vec, 0, sizeof(vec));
  for (long long int i = 0; i < n; i++) {
    string s = v[i];
    long long int len = s.length();
    for (long long int j = 0; j < len; j++) {
      vec[i][s[j] - 'a']++;
    }
    vec[i][6] = len;
  }
  long long int cnt = 0;
  long long int temp[1][7];
  memset(temp, 0, sizeof(temp));
  for (long long int i = 0; i < n; i++) {
    long long int maxi = 0;
    for (long long int j = 0; j < 6; j++) maxi = max(vec[i][j], maxi);
    if (maxi > vec[i][6] - maxi && cnt == 0) {
      cnt = max(cnt, 1ll);
      for (long long int k = 0; k < 7; k++) temp[0][k] += vec[i][k];
    } else {
      maxi = 0;
      for (long long int j = 0; j < 6; j++)
        maxi = max(vec[i][j] + temp[0][j], maxi);
      long long int tot = temp[0][6] + vec[i][6] - maxi;
      if (maxi > tot) {
        cnt++;
        for (long long int k = 0; k < 7; k++) temp[0][k] += vec[i][k];
      }
    }
  }
  cout << cnt << "\n";
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
