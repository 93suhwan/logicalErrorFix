#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = -1;
    int b = -1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != s[i + 1]) {
        a = i + 1;
        b = i + 2;
        break;
      }
    }
    cout << a << ' ' << b << '\n';
  }
  return 0;
}
