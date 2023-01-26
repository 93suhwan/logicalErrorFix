#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> v(3);
  long long m;
  cin >> v[0] >> v[1] >> v[2] >> m;
  long long mx = v[0] + v[1] + v[2] - 3;
  sort(v.begin(), v.end(), greater<long long>());
  long long mn = v[0] - v[1] - v[2] - 1;
  if (mn <= m && m <= mx)
    cout << "YES" << ("\n");
  else
    cout << "NO" << ("\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long testcase;
  cin >> testcase;
  while (testcase--) {
    solve();
  }
  return 0;
}
