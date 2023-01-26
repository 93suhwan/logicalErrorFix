#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> m;
vector<long long int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    long long int ans = 0, s1 = 1, s2 = 1;
    while (true) {
      if (rb == rd || cb == cd) break;
      if (rb + s1 > n || rb + s1 < 1) s1 *= -1;
      if (cb + s2 > m || cb + s2 < 1) s2 *= -1;
      rb += s1;
      cb += s2;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
