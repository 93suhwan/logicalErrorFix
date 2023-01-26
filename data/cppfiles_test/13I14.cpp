#include <bits/stdc++.h>
unsigned long long int M = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (s.length() % 2 != 0 || s.length() == 2)
      cout << "NO\n";
    else {
      long long int a = 0, b = 0, c = 0;
      for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A')
          a++;
        else if (s[i] == 'B')
          b++;
        else
          c++;
      }
      if (a + c == b)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
