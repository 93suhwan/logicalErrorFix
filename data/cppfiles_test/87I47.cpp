#include <bits/stdc++.h>
using namespace std;
long long int MAX = 1e9 + 7;
long long int mod = 1e9 + 7;
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> ar;
  for (long long int y = 0; y < m; y++) {
    long long int a;
    cin >> a;
    ar.push_back(a);
  }
  long long int res = 0;
  unordered_map<long long int, long long int> mp;
  for (long long int x = m - 1; x >= 0; x--) {
    long long int c = ar[x];
    if (mp[ar[x]]) {
      ar[x] += mp[ar[x]];
    }
    mp[c]++;
  }
  for (long long int x = 0; x < m; x++) {
    for (long long int y = 0; y < x; y++) {
      if (ar[y] < ar[x]) res++;
    }
  }
  cout << res << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int x = 0; x < t; x++) {
    solve();
  }
  cerr << "[Execution : " << (1.0 * clock()) / CLOCKS_PER_SEC << "s]\n";
  return 0;
}
