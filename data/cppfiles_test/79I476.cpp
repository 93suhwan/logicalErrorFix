#include <bits/stdc++.h>
using namespace std;
int t, n, i, j, x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> m;
    int f = 0;
    int num = 0;
    for (i = 0; i < n; i++) {
      if (int(s[i] - '0') % 2 == 0) {
        cout << 1 << "\n";
        cout << s[i] << "\n";
        f = 1;
        break;
      }
      if (i > 0 && s[i] == '5') {
        cout << 2 << "\n";
        cout << s[0] << s[i] << "\n";
        f = 1;
        break;
      }
      num = num * 10 + (int(s[i] - '0'));
      if ((num % 2 == 0 || num % 3 == 0 || num % 5 == 0 || num % 7 == 0 ||
           num % 11 == 0) &&
          num > 11) {
        int x = log10(num) + 1;
        cout << x << "\n";
        cout << num << "\n";
        f = 1;
        break;
      }
    }
    if (f == 1) continue;
  }
}
