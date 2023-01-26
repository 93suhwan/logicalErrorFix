#include <bits/stdc++.h>
using namespace std;
void generate(int open, int close, string str) {
  if (open == 0) {
    while (close--) {
      str.push_back(')');
    }
    cout << str << endl;
  }
  if (open == 0 && close == 0) {
    cout << str << endl;
  }
  if (open == close) {
    generate(open - 1, close, str + '(');
  } else if (open < close) {
    generate(open - 1, close, str + '(');
    generate(open, close - 1, str + ')');
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    generate(n, n, s);
  }
  return 0;
}
