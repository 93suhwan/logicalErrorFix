#include <bits/stdc++.h>
using namespace std;
void init() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0)
        s += '(';
      else
        s += ')';
    }
    int x = 2 * n - 1;
    cout << s << '\n';
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < 2 * n; j++) {
        if (s[j] == ')' && j < x) {
          s[j] = '(';
          s[j + 1] = ')';
          j++;
        }
      }
      x--;
      cout << s << '\n';
    }
  }
  return 0;
}
