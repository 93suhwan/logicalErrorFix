#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long MOD = 1000000007;
void solve() {
  int n;
  cin >> n;
  string s = "";
  char c = '(';
  for (int i = 0; i < (2 * n); i++) {
    s += c;
    if (c == '(')
      c = ')';
    else
      c = '(';
  }
  cout << s << endl;
  int p1 = 1;
  int p2 = 2;
  for (int i = 0; i < (n - 1); i++) {
    swap(s[i + 1], s[(i + 1) * 2]);
    cout << s << endl;
    ;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
}
