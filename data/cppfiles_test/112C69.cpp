#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const long long mxN = 1000000;
long long ii = 1;
void solve() {
  vector<long long> v(3);
  long long m;
  cin >> v[0] >> v[1] >> v[2] >> m;
  sort(v.rbegin(), v.rend());
  long long mn = 0, mx = 0;
  mn = max(0LL, v[0] - 1 - (v[1] + v[2]));
  if (v[0] > 1) mx += v[0] - 2 + 1;
  if (v[1] > 1) mx += v[1] - 2 + 1;
  if (v[2] > 1) mx += v[2] - 2 + 1;
  if (m >= mn && m <= mx)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long TestCase = 1;
  cin >> TestCase;
  while (TestCase--) solve();
  return 0;
}
