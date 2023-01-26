#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200005, mod = 1000000007;
long long int to_num(string s) { return stoi(s); }
void print_decimal_ans(double ans) { printf("%.15lf\n", ans); }
string to_string_(char c) {
  string x = "1";
  x[0] = c;
  return x;
}
const long long int N = 1e6 + 1;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' and t[i] == '1') {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
