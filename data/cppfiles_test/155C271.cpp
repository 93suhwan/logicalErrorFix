#include <bits/stdc++.h>
using namespace std;
long long const max1 = 1e5 + 5;
long long const mod = 1e9 + 7;
long long inf = 1e18;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  long long o = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '1') {
      o++;
    }
  }
  if (o == 0 || o == n) {
    for (long long i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    return;
  }
  map<long long, long long> index;
  vector<long long> l, dl;
  for (long long i = 0; i < n; i++) {
    index[a[i]] = i;
    if (s[i] == '1') {
      l.push_back(a[i]);
    } else {
      dl.push_back(a[i]);
    }
  }
  sort(l.begin(), l.end());
  sort(dl.begin(), dl.end());
  long long p = 1;
  long long ans[n];
  for (auto x : dl) {
    ans[index[x]] = p;
    p++;
  }
  for (auto x : l) {
    ans[index[x]] = p;
    p++;
  }
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    cout << "\n";
  }
}
