#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string ch = "";
    long long int n;
    cin >> n;
    string s[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    ch += s[0];
    for (int i = 0; i < n - 3; i++) {
      if (s[i][1] == s[i + 1][0]) {
        ch += s[i + 1][1];
      } else {
        ch += s[i + 1];
      }
    }
    if (ch.length() != n) {
      ch += "a";
    }
    cout << ch << "\n";
  }
  return 0;
}
