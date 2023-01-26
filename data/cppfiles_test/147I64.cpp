#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    if (s[0] != s[s.size() - 1] && s.size() == 2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
