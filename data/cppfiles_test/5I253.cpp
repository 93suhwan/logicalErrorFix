#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, i, j, c = 0, c1 = 0;
    cin >> n;
    string s, e;
    cin >> e >> s;
    for (i = 0; i < (n); i++) {
      if (e[i] == '0' && s[i] == '1') {
        c++;
        s[i] = '0';
        e[i] = '2';
      }
    }
    cout << e << " " << s;
    for (i = 0; i < (n); i++) {
      if (i - 1 >= 0 && e[i - 1] == '1') {
        if (s[i] == '1') {
          e[i - 1] = '0';
          c++;
        }
      } else if (i + 1 < n && e[i + 1] == '1') {
        if (s[i] == '1') {
          c++;
          e[i + 1] = '0';
        }
      }
    }
    cout << c << "\n";
  }
}
