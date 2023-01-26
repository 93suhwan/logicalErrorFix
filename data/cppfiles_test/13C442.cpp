#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int a = 0, b = 0, c = 0;
    for (auto ch : str) {
      if (ch == 'A')
        a++;
      else if (ch == 'B')
        b++;
      else
        c++;
    }
    if (b == (a + c))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
