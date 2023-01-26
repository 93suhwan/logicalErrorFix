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
map<int, bool> mp;
void solve() {
  int n, x;
  bool flag = 0;
  cin >> n >> x;
  if (x % 2 == 0) flag = 1;
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    if (mp[x]) flag = 1;
  }
  if (flag)
    cout << "NO";
  else
    cout << "YES";
}
int main() {
  long long k = 2;
  for (long long i = 3; i <= 12; ++i) {
    k *= i;
    mp[k] = 1;
  }
  int q = 1;
  cin >> q;
  while (q--) {
    solve();
    cout << '\n';
  }
}
