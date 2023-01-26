#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  for (long long i = 0; i <= n - 1; i++) {
    cin >> a[i].first, a[i].second = i;
  }
  string s;
  cin >> s;
  sort(a.begin(), a.end());
  long long p = n;
  for (long long i = n - 1; i >= 0; i--) {
    if (s[a[i].second] == '1') {
      a[i].first = p;
      p--;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (s[a[i].second] == '0') {
      a[i].first = p;
      p--;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    swap(a[i].first, a[i].second);
  }
  sort(a.begin(), a.end());
  for (long long i = 0; i <= n - 1; i++) {
    cout << a[i].second << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
