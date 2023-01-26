#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1E9 + 7;
const long long int MOD = 998244353;
const long long int N = 1E6 + 5;
void solve() {
  long long int n, m, sum = 0;
  cin >> n;
  vector<long long int> v(n);
  for (long long int &i : v) {
    cin >> i;
    sum += i;
  }
  cin >> m;
  sort((v).begin(), (v).end());
  vector<pair<long long int, long long int> > d(m);
  for (long long int i = 0; i < m; i++) {
    cin >> d[i].first;
    cin >> d[i].second;
  }
  for (long long int i = 0; i < m; i++) {
    vector<long long int> t = v;
    long long int ans = 0;
    long long int sum2 = sum;
    long long int def = d[i].first;
    long long int att = d[i].second;
    long long int a =
        (long long int)(upper_bound(v.begin(), v.end(), def) - v.begin());
    if (a == 0) {
      sum2 -= v[0];
    } else {
      ans += def - v[a - 1];
      sum2 -= v[a - 1];
    }
    if (att > sum2) {
      ans += (att - sum2);
    }
    cout << ans << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
