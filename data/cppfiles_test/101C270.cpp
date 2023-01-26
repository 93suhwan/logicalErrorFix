#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  vector<long long int> b, r;
  for (long long int j = 0; j < n; j++) {
    if (s[j] == 'R')
      r.push_back(a[j]);
    else if (s[j] == 'B')
      b.push_back(a[j]);
  }
  long long int B = b.size(), R = r.size();
  bool ok = true;
  sort(b.begin(), b.end());
  for (long long int j = 0; j < B; j++) {
    if (b[j] <= j) {
      ok = false;
    }
  }
  sort(r.begin(), r.end(), greater<long long int>());
  for (long long int j = 0; j < R; j++) {
    if (r[j] > n - j) ok = false;
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
