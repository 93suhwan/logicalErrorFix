#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    {
      int e = 0;
      for (auto x : s)
        if (x == 'E') e++;
      if (e + 1 == s.size())
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
