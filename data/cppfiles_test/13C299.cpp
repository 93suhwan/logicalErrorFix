#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
void solve() {
  string s;
  cin >> s;
  vector<int> v(3, 0);
  for (auto i : s) v[i - 'A']++;
  if (v[1] == v[0] + v[2]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
