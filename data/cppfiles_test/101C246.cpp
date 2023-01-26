#include <bits/stdc++.h>
using namespace std;
const long long mod = (1e+9) + 7;
bool f(const pair<long long, long long> &a,
       const pair<long long, long long> &b) {
  if (a.second < b.second) {
    return true;
  }
  if (a.second > b.second) return false;
  return a.first < b.first;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
  }
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B')
      a[i].second = 0;
    else
      a[i].second = 1;
  }
  sort(a.begin(), a.end(), f);
  bool flag = true, part = false;
  for (long long i = 0; i < n; i++) {
    if (a[i].second == 1) part = true;
    if (!part) {
      if (a[i].first < i + 1) flag = false;
    } else {
      if (a[i].first > i + 1) flag = false;
    }
  }
  if (!flag)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
