#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool found = false;
    for (int i = 0; i < n and !found; i++) {
      for (int j = i + 1; j < n and !found; j++) {
        int a = 0;
        int b = 0;
        for (int k = i; k <= j; k++) {
          if (s[k] == 'a')
            a++;
          else
            b++;
        }
        if (a == b) {
          cout << i + 1 << ' ' << j + 1 << '\n';
          found = true;
        }
      }
    }
    if (!found) cout << -1 << ' ' << -1 << '\n';
  }
}
