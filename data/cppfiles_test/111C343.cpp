#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int abc = 'z' - 'a' + 1;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << string(i, '(') << string(i, ')') << string(n - i, '(')
         << string(n - i, ')') << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _t;
  cin >> _t;
  for (int _i = 0; _i < _t; _i++) {
    solve();
  }
  return 0;
}
