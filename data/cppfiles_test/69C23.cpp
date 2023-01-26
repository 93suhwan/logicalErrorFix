#include <bits/stdc++.h>
using namespace std;
long long int solve(string s, string w) {
  long long int a, b, c, i, j, k;
  i = 0;
  j = 0;
  a = s.length();
  b = w.length();
  for (i = 0; i < s.length(); i++) {
    if (j == w.length()) break;
    if (s.at(i) == w.at(j)) {
      b--;
      a--;
      j++;
    }
  }
  return a + b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, T;
  cin >> T;
  for (q = 1; q <= T; q++) {
    string s;
    cin >> s;
    unsigned long long int a, b, c, i, j, k;
    long long int ans = 1e10;
    b = 1;
    for (i = 1; i <= 62; i++) {
      a = b;
      b = b * 2;
      string w = "";
      while (a > 0) {
        char ch = a % 10 + '0';
        w += ch;
        a /= 10;
      }
      reverse(w.begin(), w.end());
      ans = min(ans, solve(s, w));
    }
    cout << ans << "\n";
  }
  return 0;
}
