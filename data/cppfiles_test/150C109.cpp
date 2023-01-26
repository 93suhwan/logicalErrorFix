#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e11;
const long long mod = 1e9 + 7;
const long long inf = 1000000000000000000;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long mx = a[n - 1];
  long long c0 = 0, c1 = 0, c2 = 0;
  map<long long, long long> freq;
  for (long long i = 0; i < n; i++) {
    freq[a[i]]++;
    if (a[i] % 3 == 0) {
      c0++;
    } else if (a[i] % 3 == 1) {
      c1++;
    } else if (a[i] % 3 == 2) {
      c2++;
    }
  }
  if (mx % 3 == 0) {
    if (c1 == 0 && c2 == 0) {
      cout << mx / 3 << '\n';
      return;
    } else {
      cout << (mx / 3 - 1) + 2 << '\n';
      return;
    }
  } else if (mx % 3 == 1) {
    if (c2 == 0) {
      cout << mx / 3 + 1 << '\n';
    } else if (freq[1] == 0 && freq[mx - 1] == 0) {
      cout << (mx / 3 - 1) + 2 << '\n';
      return;
    } else {
      cout << (mx / 3 - 1) + 3 << '\n';
      return;
    }
  } else if (mx % 3 == 2) {
    if (c1 == 0) {
      cout << mx / 3 + 1 << '\n';
      return;
    } else {
      cout << mx / 3 + 2 << '\n';
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
