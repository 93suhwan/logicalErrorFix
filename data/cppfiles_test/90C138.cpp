#include <bits/stdc++.h>
using namespace std;
const int MOD99 = 998244353;
const int MOD97 = 1e9 + 7;
const int maxn = 2e5 + 5;
vector<long long> arr, brr;
set<long long> sp;
long long t, x, y;
string s;
void solve() {
  cin >> t;
  while (t--) {
    cin >> x >> y;
    int t = y % x;
    if (t == 0)
      cout << x << endl;
    else if (y < x)
      cout << x + y << endl;
    else {
      x = y - t;
      cout << y - (y - x) / 2 << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  solve();
  return 0;
}
