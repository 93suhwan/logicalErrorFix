#include <bits/stdc++.h>
using namespace std;
string rep(int n, char c) {
  string s;
  for (int i = 0; i < n; i++) s += c;
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 'a' << endl;
      continue;
    }
    string ans;
    int c = n / 2;
    if (n & 1)
      ans = rep(c, 'a') + 'b' + rep(c - 1, 'a') + 'c';
    else
      ans = rep(c, 'a') + 'b' + rep(c - 1, 'a');
    cout << ans << endl;
  }
}
