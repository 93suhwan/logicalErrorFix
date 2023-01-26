#include <bits/stdc++.h>
using namespace std;
const long long mxlli = 1e18;
const int mod = 1e9 + 7;
const int msize = 2e5 + 2;
int solv(int T) {
  int n, i;
  cin >> n;
  vector<long long> a(n);
  long long r = -mxlli, mn = mxlli;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  if (n == 1) {
    cout << a[0] << "\n";
    return 0;
  }
  for (i = 1; i < n; i++) {
    r = max(r, a[i - 1] - a[i]);
  }
  cout << max(mn, r) << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcases = 1;
  cin >> testcases;
  for (int T = 1; T <= testcases; T++) {
    solv(T);
  }
}
