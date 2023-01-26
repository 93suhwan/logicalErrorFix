#include <bits/stdc++.h>
using namespace std;
void init() {}
int main() {
  init();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests;
  cin >> tests;
  while (tests--) {
    string s;
    cin >> s;
    long long int n = s.length();
    if (n % 2)
      cout << "NO\n";
    else {
      long long int i = 0, j = n / 2;
      while (j < n) {
        if (s[i] != s[j]) break;
        i++, j++;
      }
      cout << (j == n ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
