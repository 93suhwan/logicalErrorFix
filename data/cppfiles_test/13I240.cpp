#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto i : s) {
      if (i == 'A')
        a++;
      else if (i == 'B')
        b++;
      else
        c++;
    }
    if (a <= b) {
      int k = a;
      a -= k;
      b -= k;
    } else {
      int k = b;
      a -= k;
      b -= k;
    }
    if (b == c)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
