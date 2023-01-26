#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    cin >> s;
    int a = 1, b = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'L') {
        b++;
      } else if (s[i] == 'R') {
        if (b == m) {
          b--;
        }
      } else if (s[i] == 'U') {
        a++;
      } else {
        if (a == n) {
          a--;
        }
      }
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}
