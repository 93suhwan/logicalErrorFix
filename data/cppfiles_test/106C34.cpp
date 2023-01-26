#include <bits/stdc++.h>
using namespace std;
const int inf = 2000 + 9;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const long double ep = 1.000000001;
void solve(int t) {
  int n;
  cin >> n;
  int c = 2;
  for (int i = 0; i < n; i++) {
    cout << c << " ";
    c++;
  }
  cout << '\n';
}
void local() {}
int32_t main() {
  local();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(8) << fixed;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
