#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++) {
      s += '(';
    }
    for (int i = 0; i < n; i++) {
      s += ')';
    }
    cout << s << endl;
    for (int i = n - 1; i < 2 * n - 2; i++) {
      swap(s[i], s[i + 1]);
      cout << s << endl;
    }
  }
  return 0;
}
