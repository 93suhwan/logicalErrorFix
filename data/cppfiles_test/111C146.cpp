#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char s[(2 * n)];
    for (int i = 0; i < 2 * n; i++) {
      if (i % 2 == 0)
        s[i] = '(';
      else
        s[i] = ')';
    }
    int it = 0;
    int count = 1;
    while (it < n) {
      int cal = (2 * it);
      if (count == 1) {
        count++;
        for (auto temp : s) cout << temp;
        cout << '\n';
      } else {
        char type;
        type = s[it];
        s[it] = s[cal];
        s[cal] = type;
        for (auto temp : s) cout << temp;
        cout << '\n';
      }
      it++;
    }
  }
}
