#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TT;
  cin >> TT;
  for (int tt = 1; tt <= TT; tt++) {
    int n;
    cin >> n;
    string res, fixed;
    for (int i = 0; i < n - 1; i++) fixed += "()";
    for (int i = 0; i < n; i++) {
      res = "(";
      for (int j = 0; j < i; j++) {
        res += "()";
      }
      res += ")";
      for (int j = i; j < n - 1; j++) res += "()";
      cout << res << "\n";
    }
  }
  return 0;
}
