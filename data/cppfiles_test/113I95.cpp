#include <bits/stdc++.h>
using namespace std;
long long int lim = 1e9 + 7;
long long int power(long long int a, long long int b, long long int lim) {
  long long int res = 1;
  while (b) {
    if (b & 1) res = (res * a) % lim;
    a = (a * a) % lim;
    b /= 2;
  }
  return res;
}
void solve() {
  long long int n, m, x, y, i, j, sum = 0;
  cin >> n;
  vector<long long int> a(n + 1, 0);
  for (i = 1; i < n + 1; i++) cin >> a[i], sum += a[i];
  sort(a.begin(), a.end());
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    j = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (j == 0) j = 1;
    if (j == n) j = n - 1;
    if (x <= a[j] && y <= sum - a[j])
      cout << 0 << endl;
    else
      cout << min(max(x - a[j], (long long int)0) +
                      max(y - (sum - a[j]), (long long int)0),
                  max(x - a[j - 1], (long long int)0) +
                      max(y - (sum - a[j - 1]), (long long int)0))
           << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
