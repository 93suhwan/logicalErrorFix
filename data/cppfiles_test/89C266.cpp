#include <bits/stdc++.h>
using namespace std;
const int E5 = 1e5;
const int E6 = 1e6;
const int E7 = 1e7;
const int E9 = 1e9;
const int N = 5e5 + 7;
const long long INF = 1e18;
const double PI = 3.14159265358979;
const long long mod = E9 + 7;
void solve() {
  int n;
  bool flag = 0;
  cin >> n;
  for (int i = 2; i <= n + 1; ++i) {
    int x;
    cin >> x;
    bool ok = 0;
    for (int j = i; j > 1; --j) {
      if (x % j) {
        ok = 1;
        break;
      }
    }
    if (!ok) flag = 1;
  }
  if (flag)
    cout << "NO";
  else
    cout << "YES";
}
int main() {
  int q = 1;
  cin >> q;
  while (q--) {
    solve();
    cout << '\n';
  }
}
