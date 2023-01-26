#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX = 1e6;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  vector<long long> x(n);
  for (long long i = 0; i < n; i++) cin >> x[i];
  vector<string> s(n);
  for (long long i = 0; i < n; i++) cin >> s[i];
  vector<long long> ans;
  long long mx = -1;
  for (long long mask = 0; mask < (1 << n); mask++) {
    long long cur = 0;
    for (long long i = 0; i < n; i++) {
      if (mask & (1 << i))
        cur += x[i];
      else
        cur -= x[i];
    }
    vector<long long> subjects[2 * n + 1];
    for (long long j = 0; j < m; j++) {
      long long t = 0;
      for (long long i = 0; i < n; i++) {
        if (s[i][j] == '1') {
          if (mask & (1 << i))
            t--;
          else
            t++;
        }
      }
      subjects[t + n].push_back(j);
    }
    vector<long long> present(m);
    long long nxt = 1;
    for (long long i = 0; i < 2 * n + 1; i++) {
      for (auto j : subjects[i]) {
        present[j] = nxt;
        cur += nxt * (i - n);
        nxt++;
      }
    }
    if (cur > mx) {
      mx = cur;
      ans = present;
    }
  }
  for (auto i : ans) cout << i << " ";
  cout << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
