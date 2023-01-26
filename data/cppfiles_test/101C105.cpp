#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0LL ? a : gcd(b, a % b); }
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      a[i].second = -1;
      if (a[i].first < 1) {
        cout << "NO\n";
        return;
      }
    } else {
      a[i].second = 1;
      if (a[i].first > n) {
        cout << "NO\n";
        return;
      }
    }
  }
  sort(a.begin(), a.end());
  int bc = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second == -1) {
      bc++;
      if (bc > a[i].first) {
        cout << "NO\n";
        return;
      }
    }
  }
  int rc = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].second == 1) {
      rc++;
      if (rc > n - a[i].first + 1) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
