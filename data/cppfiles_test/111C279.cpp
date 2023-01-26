#include <bits/stdc++.h>
using namespace std;
void generate(int open, int close, string str, int &count) {
  if (count == 0) return;
  if (open == 0) {
    while (close--) {
      str.push_back(')');
    }
    cout << str << endl;
    count--;
  }
  if (open == 0 && close == 0) {
    cout << str << endl;
    count--;
  }
  if (open == close) {
    generate(open - 1, close, str + '(', count);
  } else if (open < close) {
    generate(open - 1, close, str + '(', count);
    generate(open, close - 1, str + ')', count);
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
    generate(n, n, s, n);
  }
  return 0;
}
