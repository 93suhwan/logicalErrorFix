#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long int mod = 1e9 + 7;
long long ll bsrch(long long ll l, long long ll r, vector<long long ll> &a,
                   long long ll k) {
  if (l >= a.size() || r < 0) return -1;
  if (l == r) {
    if (a[l] == k)
      return l;
    else
      return -1;
  }
  long long ll mid = l + (r - l) / 2;
  if (a[mid] == k)
    return k;
  else if (a[mid] > k)
    return bsrch(l, mid - 1, a, k);
  else
    return bsrch(mid + 1, r, a, k);
}
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if ((c < a && c < b) || (c > a && c > b)) {
    cout << "-1\n";
    return;
  }
  long long int n = 2 * abs(a - b);
  if (a > n || b > n || c > n) {
    cout << "-1\n";
    return;
  }
  long long int d = c + (n / 2);
  while (d > n) d -= n;
  cout << d << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  long long int i = 1;
  while (i <= t) {
    solve();
    i++;
  }
}
