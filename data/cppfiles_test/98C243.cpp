#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 200010;
void solve() {
  long long n;
  cin >> n;
  string str;
  cin >> str;
  for (long long i = 1; i < n; i++) {
    if (str[i] != str[i - 1]) {
      cout << i << ' ' << i + 1 << '\n';
      return;
    }
  }
  cout << "-1 -1\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _t = 1;
  cin >> _t;
  for (int i = 1; i <= _t; i++) {
    solve();
  }
}
