#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> s(n - 2);
    for (int i = 0; i < n - 2; i++) {
      cin >> s[i];
    }
    string res = "";
    res += s[0][0];
    for (int i = 0; i < n - 3; i++) {
      if (s[i][1] == s[i + 1][0])
        res += s[i][1];
      else {
        res += s[i][1];
        res += s[i + 1][0];
      }
    }
    res += s[n - 3][1];
    if (res.size() < n) res += "b";
    cout << res << endl;
  }
}
