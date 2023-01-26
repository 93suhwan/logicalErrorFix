#include <bits/stdc++.h>
using namespace std;
const long long N = 200 * 1000 + 7;
vector<vector<long long>> b(10);
long long ans[N];
long long f(string s, char c) {
  long long cnt = 0;
  for (auto z : s) {
    if (z == c) cnt++;
  }
  return cnt - (s.size() - cnt);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (char c = 'a'; c <= 'e'; c++) {
        b[c - 'a'].push_back(f(s, c));
      }
    }
    long long ans = 0;
    for (char c = 'a'; c <= 'e'; c++) {
      sort(b[c - 'a'].begin(), b[c - 'a'].end(), greater<long long>());
      long long cnt = 0;
      if (b[c - 'a'][0] > 0) {
        long long sum = 0;
        for (long long i = 0; i < b[c - 'a'].size(); i++) {
          sum += b[c - 'a'][i];
          cnt++;
          if (sum <= 0) {
            cnt--;
            break;
          }
        }
      }
      ans = max(ans, cnt);
      b[c - 'a'].clear();
    }
    cout << ans << endl;
  }
  return 0;
}
