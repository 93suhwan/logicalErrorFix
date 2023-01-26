#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  ;
  cin >> t;
  while (t--) {
    int flag = 0;
    string ch = "";
    long long int n;
    cin >> n;
    string s[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n - 2; i++) {
      if (i == 0) {
        ch += s[i];
        continue;
      }
      if (s[i][0] == s[i - 1][1]) {
        ch += s[i][1];
      } else {
        ch += s[i];
        flag = 1;
      }
    }
    if (ch.length() != n) {
      ch += "a";
    }
    cout << ch << "\n";
  }
  return 0;
}
