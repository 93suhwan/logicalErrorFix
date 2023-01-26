#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const int inf = 1e9;
const int N = 201;
bool flag;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b && a)
    cout << 1;
  else if (abs(a - b) == 1)
    cout << -1;
  else if (a == b && a == 0)
    cout << 0;
  else
    cout << 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    flag = 0;
    solve();
    cout << '\n';
  }
  return 0;
}
