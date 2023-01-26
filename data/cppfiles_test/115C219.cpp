#include <bits/stdc++.h>
using namespace std;
long long int n, p;
vector<long long int> a;
vector<long long int> d;
bool check(long long int m) {
  long long int sum = 0;
  for (long long int i = 0; i < n - 1; i++) {
    sum += min(m, d[i]);
    if (sum >= p) {
      return true;
    }
  }
  sum += m;
  if (sum >= p) {
    return true;
  }
  return false;
}
void solve() {
  cin >> n >> p;
  a.clear();
  d.clear();
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    a.push_back(x);
  }
  for (long long int i = 1; i < n; i++) {
    d.push_back(a[i] - a[i - 1]);
  }
  long long int l = 0;
  long long int r = p;
  long long int m;
  long long int ma = p;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (check(m)) {
      ma = min(m, ma);
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ma;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
