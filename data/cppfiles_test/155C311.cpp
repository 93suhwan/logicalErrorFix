#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1000000000;
void solve() {
  long long n;
  string s;
  cin >> n;
  vector<long long> p(n);
  vector<long long> ans(n);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    p[--x] = i;
  }
  cin >> s;
  long long ones = 1;
  long long nuls = 1;
  for (long long i = 0; i < n; i++)
    if (s[i] == '0') ++nuls;
  for (long long i = 0; i < n; i++) {
    if (s[p[i]] == '0') {
      ans[p[i]] = ones;
      ++ones;
    } else {
      ans[p[i]] = nuls;
      ++nuls;
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
