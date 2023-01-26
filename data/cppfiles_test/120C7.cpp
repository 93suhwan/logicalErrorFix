#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int AM = 2e5 + 5;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<long long int>> a(AM + 1, vector<long long int>(32 + 1, 0));
  for (__typeof(0) i = 0; i < AM; ++i) {
    for (__typeof(0) j = 0; j < 32; ++j) {
      if (i > 0) a[i][j] = a[i - 1][j];
      if ((i & (1 << j)) != 0) a[i][j]++;
    }
  }
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    long long int ans = mod;
    for (__typeof(0) i = 0; i < 32; ++i)
      ans = min(ans, (r - l + 1) - (a[r][i] - a[l - 1][i]));
    cout << ans << endl;
  }
  return 0;
}
