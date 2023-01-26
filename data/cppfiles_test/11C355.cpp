#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int PINF = INT_MAX;
const int NINF = INT_MIN;
void solve() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  vector<vector<int> > abcde(5, vector<int>(n, 0));
  vector<int> l(n);
  for (long long i = 0; i < n; i++) {
    l[i] = v[i].size();
    for (auto c : v[i]) {
      abcde[c - 'a'][i]++;
    }
  }
  for (long long i = 0; i < 5; i++) {
    for (long long j = 0; j < n; j++) {
      abcde[i][j] *= 2;
      abcde[i][j] -= l[j];
    }
  }
  int ans = INT_MIN;
  for (long long i = 0; i < 5; i++) {
    sort(abcde[i].begin(), abcde[i].end(), greater<int>());
    int s = 0, currLen = 0;
    for (long long j = 0; j < n; j++) {
      if (s + abcde[i][j] > 0) {
        s += abcde[i][j];
        currLen++;
      }
    }
    ans = max(ans, currLen);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  int i = 1;
  while (i <= t) {
    solve();
    i++;
  }
  return 0;
}
