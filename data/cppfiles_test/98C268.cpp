#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    s += '*';
    int f = 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        cout << i + 1 << " " << i + 2 << "\n";
        f = 0;
        break;
      } else if (s[i] == 'b' && s[i + 1] == 'a') {
        cout << i + 1 << " " << i + 2 << "\n";
        f = 0;
        break;
      }
    }
    if (f) cout << -1 << " " << -1 << "\n";
  }
}
