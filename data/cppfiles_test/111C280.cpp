#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char s[101] = {0};
    for (int i = 0; i < n; i++) {
      s[i] = '(';
      s[2 * n - i - 1] = ')';
    }
    cout << s << endl;
    for (int i = 1; i < n; i++) {
      swap(s[i], s[2 * n - i - 1]);
      cout << s << endl;
      swap(s[2 * n - i - 1], s[i]);
    }
  }
}
