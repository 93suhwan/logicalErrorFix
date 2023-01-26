#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s[n - 2];
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    string a = s[0];
    for (int i = 1; i < n - 2; i++) {
      if (s[i][0] == s[i - 1][1])
        a += s[i][1];
      else
        a += s[i];
    }
    if (a.length() != n) a += 'a';
    cout << a << endl;
  }
}
