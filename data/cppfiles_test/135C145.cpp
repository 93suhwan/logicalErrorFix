#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long int;
using lli = long long int;
using ld = long double;
using ll = long long;
void solve() {
  lli n, k;
  cin >> n >> k;
  vector<lli> v(n);
  for (int i = 0; i < (int)(n); ++i) cin >> v[i];
  sort((v).begin(), (v).end());
  lli ans{0};
  lli t = k;
  for (lli i{n - 1}; i >= 0 && t > 0; i--) {
    ans += v[i - k] / v[i];
    t--;
  }
  lli p = n - 2 * k;
  for (int i = 0; i < (int)(p); ++i) {
    ans += v[i];
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int T{1};
  cin >> T;
  while (T--) {
    solve();
  }
}
