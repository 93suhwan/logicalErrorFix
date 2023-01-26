#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
const long long inf = 1e18;
const int SZ = 101;
const double eps = 1e-9;
void solve() {
  vector<int> v(3);
  for (long long i = 0; i < 3; i++) cin >> v[i];
  sort(v.begin(), v.end());
  if (v[2] == v[1] + v[0]) {
    cout << "YES\n";
  } else if (v[0] == v[1]) {
    if (v[2] % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else if (v[0] == v[2]) {
    if (v[1] % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else if (v[2] == v[1]) {
    if (v[0] % 2 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else {
    cout << "NO\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  long long T = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
