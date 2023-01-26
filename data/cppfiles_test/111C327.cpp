#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6;
const int MOD = 1e9 + 7;
const string ALPHA = "abcdefghijklmnopqrstuvwxyz";
const double PI = 3.1415926535;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      string s = "";
      int bal = 0;
      for (int j = 0; j < 2 * (n - i); j += 1) {
        s += (j % 2 ? ')' : '(');
      }
      for (int j = 0; j < i; j += 1) {
        s += '(';
      }
      for (int j = 0; j < i; j += 1) {
        s += ')';
      }
      cout << s << '\n';
      ;
    }
  }
}
