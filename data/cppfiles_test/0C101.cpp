#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (j & 1) s[i][j] = 'Z' - s[i][j] + 'A';
    }
  }
  map<string, long long> mp;
  for (long long i = 0; i < n; i++) mp.insert({s[i], i + 1});
  for (auto it : mp) {
    cout << it.second << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
