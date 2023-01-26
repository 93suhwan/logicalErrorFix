#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long al = 0;
    string s[n + 1];
    for (long long i = 1; i <= n - 2; i++) {
      cin >> s[i];
      if (i == 1) {
        cout << s[i];
      } else {
        if (s[i][0] != s[i - 1][1]) {
          cout << s[i];
          al = 1;
        } else {
          cout << s[i][1];
        }
      }
    }
    if (al == 0) {
      cout << "a";
    }
    cout << "\n";
  }
}
